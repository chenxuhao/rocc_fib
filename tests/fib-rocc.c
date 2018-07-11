//see LICENSE for license
// The following is a RISC-V program to test the 
// functionality of the fib RoCC accelerator.
// Compile with riscv64-unknown-elf-gcc fib-rocc.c -o fib-rocc.rv
// Run with spike --extension=fib pk a.out

#include <assert.h>
#include <stdio.h>
#include <stdint.h>
#include "fib.h"

int main() {
  do {
    unsigned int len = 33;
    unsigned int output = 0;
    unsigned int temp = 0;
    int fib[70];
    fib[0] = 0; fib[1] = 1;
    for(int i = 2; i < 70; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

	// Invoke the acclerator and check responses
	uint16_t addr = 1;
	printf("[INFO] Launch Fib with length=%d\n", len);
	doFib(temp, addr, len);

	printf("[INFO] Read the sequence of Fibonacci numbers\n");
	for (int i = 0; i < len; i ++) {
		doRead(temp, i);
		printf("[INFO] Fib[%d] = %d (expected %d)\n", i, temp, fib[i]);
	}
	output = temp;
	
    // Check result
    printf("check.\n");
    if(fib[len-1] == output) printf("correct\n");
    else printf("wrong\n");
  } while(0);
  printf("success!\n");
  return 0;
}
