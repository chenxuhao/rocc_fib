#include "rocc.h"
#include "mmu.h"
#include "extension.h"
#include "fib.h"

void printState(uint64_t st[25])
{
  int i,j;
  for(i = 0; i<5; i++){
     for(j = 0; j<5; j++){
       printf("%016llx ", st[i+j*5]);
     }
     printf("\n");
  }
  printf("\n");
}

int fib_t::fib(unsigned char *message, unsigned int len, unsigned char *digest) {
  return 0;
}

