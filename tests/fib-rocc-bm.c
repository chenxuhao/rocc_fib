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
	uint16_t addr = 1;
	doFib(temp, addr, len);

	for (int i = 0; i < len; i ++) {
		doRead(temp, i);
	}
	output = temp;
  } while(0);
  return 0;
}
