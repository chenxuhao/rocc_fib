//see LICENSE for license
#ifndef _RISCV_FIB_ROCC_H
#define _RISCV_FIB_ROCC_H
#include "rocc.h"
#include "mmu.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
class fib_t : public rocc_t
{
public:
  fib_t() {};
  const char* name() { return "fib"; }
  void reset() {
    msg_addr = 0;
    hash_addr = 0;
    msg_len = 0;
  }

  reg_t custom0(rocc_insn_t insn, reg_t xs1, reg_t xs2) {
    switch (insn.funct) {
      case 0: // setup msg and hash addr
        msg_addr = xs1;
        hash_addr = xs2;
        break;
      case 1: // setup msg length and run
        msg_len = xs1;
        //read message into buffer
        unsigned char* input;
        input  = (unsigned char*)malloc(msg_len*sizeof(char));
        for(uint32_t i = 0; i < msg_len; i++)
          input[i] = p->get_mmu()->load_uint8(msg_addr + i);
        unsigned char output[SHA3_256_DIGEST_SIZE];
        fib(input, msg_len, output);
        //write output
        for(uint32_t i = 0; i < SHA3_256_DIGEST_SIZE; i++)
          p->get_mmu()->store_uint8(hash_addr + i, output[i]);
        
        //clean up
        free(input);

        break;

      default:
        illegal_instruction();
    }

    return -1; // in all cases, the accelerator returns nothing
  }

private:
  reg_t msg_addr;
  reg_t hash_addr;
  reg_t msg_len;

typedef struct {
  uint64_t st[25];
  unsigned int md_len;
  unsigned int rsiz;
  unsigned int rsizw;
  unsigned int partial;
  uint8_t buf[1];
} fib_state;

void printState(uint64_t st[25]);
int fib(unsigned char *message, unsigned int len, unsigned char *digest);
};

REGISTER_EXTENSION(fib, []() { return new fib_t; })
#endif
