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
    int fib[70];
    fib[0] = 0; fib[1] = 1;
    for(int i = 2; i < 70; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    asm volatile ("fence");
    // Invoke the acclerator and check responses

    // setup accelerator with input and output
    //              opcode   rd rs1          rs2          funct   
    //asm volatile ("custom0 0, %[msg_addr], %[hash_addr], 0" : : [msg_addr]"r"(&input), [hash_addr]"r"(&output));

    // Set length and compute hash
    //              opcode   rd rs1       rs2 funct   
    asm volatile ("custom0 0, %[length], 0, 0" : : [length]"r"(len));
    asm volatile ("fence");
    // Check result
    if(fib[len-1] == output) printf("correct\n");
    else printf("wrong\n");
  } while(0);
  printf("success!\n");
  return 0;
}
