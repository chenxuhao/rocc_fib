// Define reference (software) fib
#ifndef __FIB_H
#define __FIB_H
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define ROTL64(x, y) (((x) << (y)) | ((x) >> (64 - (y))))

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

#endif
