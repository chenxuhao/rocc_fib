//see LICENSE for license
// The following is a RISC-V program to test the 
// functionality of the fib RoCC accelerator.
// Compile with riscv-gcc fib-rocc.c
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
    unsigned char input[1] = "0";
    unsigned char output[1];
    asm volatile ("fence");
    // Invoke the acclerator and check responses

    // setup accelerator with addresses of input and output
    //              opcode rd rs1          rs2          funct   
    //asm volatile ("custom0 0, %[msg_addr], %[hash_addr], 0" : : [msg_addr]"r"(&input), [hash_addr]"r"(&output));

    // Set length and compute hash
    //              opcode rd rs1      rs2 funct   
    //asm volatile ("custom0 0, %[length], 0, 1" : : [length]"r"(ilen));
    asm volatile ("fence");
    // Check result
    int i = 0;
    unsigned char result[1] = {221};
    for(i = 0; i < 1; i++){
      printf("output[%d]:%d ==? results[%d]:%d \n",i,output[i],i,result[i]);
      assert(output[i]==result[i]);
    }
  }while(0);
  printf("success!\n");
  return 0;
}
