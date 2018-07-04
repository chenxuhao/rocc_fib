// Define reference (software) fib
#ifndef __FIB_H
#define __FIB_H
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define STR1(x) #x
#define STR(x) STR1(x)
#define EXTRACT(a, size, offset) (((~(~0 << size) << offset) & a) >> offset)

#define CUSTOMX_OPCODE(x) CUSTOM_##x
#define CUSTOM_0 0b0001011
#define CUSTOM_1 0b0101011
#define CUSTOM_2 0b1011011
#define CUSTOM_3 0b1111011

#define CUSTOMX(X, rd, rs1, rs2, funct) \
  CUSTOMX_OPCODE(X)                   | \
  (rd                   << (7))       | \
  (0x7                  << (7+5))     | \
  (rs1                  << (7+5+3))   | \
  (rs2                  << (7+5+3+5)) | \
  (EXTRACT(funct, 7, 0) << (7+5+3+5+5))

#define CUSTOMX_R_R_R(X, rd, rs1, rs2, funct)           \
  asm ("mv a4, %[_rs1]\n\t"                             \
       "mv a5, %[_rs2]\n\t"                             \
       ".word "STR(CUSTOMX(X, 15, 14, 15, funct))"\n\t" \
       "mv %[_rd], a5"                                  \
       : [_rd] "=r" (rd)                                \
       : [_rs1] "r" (rs1), [_rs2] "r" (rs2)             \
       : "a4", "a5");

#define MAX 70
/*
void printState(uint64_t st[25])
{
  int i,j;
  for(i = 0; i<5; i++){
     for(j = 0; j<5; j++){
       printf("%016llx ", st[i+j*5]);
     }
     printf("\n");
  }
  printf("\n");
}
*/
void solve_fib(unsigned int input, unsigned int *output) {
    if (input == 0) {
        *output = 0;
    } else if (input == 1) {
        *output = 1;
    } else {
        unsigned int fib[MAX];
        fib[0] = 0; fib[1] = 1;
        for(int i = 2; i < input; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        *output = fib[input-1];
    }
    return;
}

#endif
