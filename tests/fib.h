// See LICENSE for license details.

#ifndef SRC_MAIN_C_ACCUMULATOR_H
#define SRC_MAIN_C_ACCUMULATOR_H

#include "xcustom.h"

#define k_DO_WRITE 0
#define k_DO_READ 1
#define k_DO_LOAD 2
#define k_DO_FIB 3

#define XCUSTOM_ACC 0

#define doWrite(y, rocc_rd, data)                                       \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, data, rocc_rd, k_DO_WRITE);
#define doRead(y, rocc_rd)                                              \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, 0, rocc_rd, k_DO_READ);
#define doLoad(y, rocc_rd, mem_addr)                                    \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, mem_addr, rocc_rd, k_DO_LOAD);
#define doFib(y, rocc_rd, data) \
  ROCC_INSTRUCTION(XCUSTOM_ACC, y, data, rocc_rd, k_DO_FIB);

#endif  // SRC_MAIN_C_ACCUMULATOR_H
