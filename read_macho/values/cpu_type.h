#ifndef CPU_TYPE_H
#define CPU_TYPE_H

#include "util/defs.h"

#include <stdint.h>
#include <stdlib.h>

typedef enum
{
  CPU_VAX = 0x01,
  CPU_ROMP = 0x02,
  CPU_NS32032 = 0x04,
  CPU_NS32332 = 0x05,
  CPU_MC680X0 = 0x06,
  CPU_X86 = 0x07,
  CPU_MIPS = 0x08,
  CPU_NS32352 = 0x09,
  CPU_MC98000 = 0x0A,
  CPU_HP_PH = 0x0B,
  CPU_ARM = 0x0C,
  CPU_MC88000 = 0x0D,
  CPU_SPARC = 0x0E,
  CPU_I860_BE = 0x0F,
  CPU_I850_LE = 0x10,
  CPU_RS_6000 = 0x11,
  CPU_POWERPC = 0x12,
  CPU_TYPE_LAST = CPU_POWERPC + 1,
} cpu_type_t;
static_assert(sizeof(cpu_type_t) == sizeof(int32_t));

#endif /* CPU_TYPE_H */