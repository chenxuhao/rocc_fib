//see LICENSE for license
// The following is a RISC-V program to test the 
// functionality of the fib RoCC accelerator.
// Compile with riscv-gcc fib-sw.c
// Run with spike --extension=fib pk a.out
#include "fib.h"

int main() {
  do {
    printf("start basic test 1.\n");
    unsigned int len = 33;
    unsigned int output = 0;
    unsigned int fib[MAX];
    fib[0] = 0; fib[1] = 1;
    for(int i = 2; i < MAX; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    solve_fib(len, &output);

    // Check result
    if(fib[len-1] == output) printf("correct\n");
    else printf("wrong\n");
  } while(0);
  printf("success!\n");
  return 0;
}
