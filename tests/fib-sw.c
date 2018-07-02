//see LICENSE for license
// The following is a RISC-V program to test the 
// functionality of the fib RoCC accelerator.
// Compile with riscv-gcc fib-sw.c
// Run with spike --extension=fib pk a.out
#include <assert.h>
#include <stdio.h>
#include <stdint.h>
//#include "fib.h"

int main() {
  do {
    printf("start basic test 1.\n");
    // Setup some test data
    unsigned int ilen = 1;
    unsigned char output[1];
    //compute hash
    //fib(input, ilen, output);
    // Check result
    int i = 0;
    unsigned char result[1];
    //fib(input, ilen, result);
    for(i = 0; i < 1; i++){
      printf("output[%d]:%d ==? results[%d]:%d \n",i,output[i],i,result[i]);
     assert(output[i]==result[i]);
    }
  } while(0);
  printf("success!\n");
  return 0;
}
