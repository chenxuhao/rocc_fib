//see LICENSE for license
// The following is a RISC-V program to test the 
// functionality of the fib RoCC accelerator.
// Compile with riscv-gcc fib-rocc.c
// Run with spike --extension=fib pk a.out

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "fib.h"

int main() {

  do {
    printf("start basic test 1.\n");
    unsigned int len = 33;
    unsigned int output = 0;
    unsigned int temp = 0;
    int fib[70];
    fib[0] = 0; fib[1] = 1;
    for(int i = 2; i < 70; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Invoke the acclerator and check responses
	asm volatile ("fence");
	// load len into FibAccelerator 2 (funct=0)
	//asm volatile ("custom0 x0, %0, 2, 0" : : "r"(len));
	CUSTOMX_R_R_R(0, temp, len, 2, 0);
	// read it back into ouput (funct=1) to verify it
	//asm volatile ("custom0 %0, x0, 2, 1" : "=r"(output));
	//CUSTOMX_R_R_R(0, output, temp, 2, 1);
	
    asm volatile ("fence");
    // Check result
    if(fib[len-1] == output) printf("correct\n");
    else printf("wrong\n");
  } while(0);
  printf("success!\n");
  return 0;
}
