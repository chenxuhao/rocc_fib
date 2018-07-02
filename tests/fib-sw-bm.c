//see LICENSE for license
// The following is a RISC-V program to test the 
// functionality of the fib RoCC accelerator.
// Compile with riscv-gcc fib-rocc.c
// Run with spike --extension=fib pk a.out

#include <stdint.h>
#include "fib.h"

int main() {
  do {
    unsigned int ilen = 1;
    unsigned char input[1] = "0"; 
    unsigned char output[1];
    //fib(input, ilen, output);
    int i = 0;
    unsigned char result[1];
    //fib(input, ilen, result);
  } while(0);
  return 0;
}
