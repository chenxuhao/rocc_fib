#include "fib.h"

int main() {
	uint64_t x = 123, y = 456, z = 0, temp=0;
	// load x into accumulator 2 (funct=0)
	CUSTOMX_R_R_R(0, temp, x, 2, 0);
	// read it back into z (funct=1) to verify it
	//CUSTOMX_R_R_R(0, z, x, 2, 1);
	//assert(z == x);
/*
	// accumulate 456 into it (funct=3)
	CUSTOMX_R_R_R(0, temp, y, 2, 3);
	//asm volatile ("custom0 x0, %0, 2, 3" : : "r"(y));
	// verify it
	CUSTOMX_R_R_R(0, z, temp, 2, 1);
	//asm volatile ("custom0 %0, x0, 2, 1" : "=r"(z));
	assert(z == x+y);
	// do it all again, but initialize acc2 via memory this time (funct=2)
	CUSTOMX_R_R_R(1, temp, &x, 2, 0); // add this instruction to translate address
	CUSTOMX_R_R_R(0, temp, temp, 2, 2);
	//asm volatile ("custom0 x0, %0, 2, 2" : : "r"(&x));
	CUSTOMX_R_R_R(0, temp, y, 2, 3);
	//asm volatile ("custom0 x0, %0, 2, 3" : : "r"(y));
	CUSTOMX_R_R_R(0, z, temp, 2, 1);
	//asm volatile ("custom0 %0, x0, 2, 1" : "=r"(z));
	assert(z == x+y);
*/
	printf("success!\n");
}
