//see LICENSE for license
// The following is a RISC-V program to test the 
// functionality of the fib RoCC accelerator.
// Compile with riscv-gcc fib-rocc.c
// Run with spike --extension=fib pk a.out
#include "fib.h"

int main() {
  do {
    unsigned int len = 33;
    unsigned int output = 0;
    solve_fib(len, &output);
  } while(0);
  return 0;
}
