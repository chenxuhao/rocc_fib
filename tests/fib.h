// Define reference (software) fib
#ifndef __FIB_H
#define __FIB_H
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
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
