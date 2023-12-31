#ifndef CPU_SUBTYPE_H
#define CPU_SUBTYPE_H

#include "util/defs.h"

#include <stdint.h>

typedef enum
{
  CPU_SUBTYPE_X86_ALL = 0x03,
  CPU_SUBTYPE_486 = 0x04,
  CPU_SUBTYPE_486SX = 0x84,
  CPU_SUBTYPE_X86_PENTIUM_M5 = 0x56,
  CPU_SUBTYPE_X86_CELERON,
  CPU_SUBTYPE_X86_CELERON_MOBILE,
  CPU_SUBTYPE_X86_PENTIUM_3,
  CPU_SUBTYPE_X86_PENTIUM_3M,
  CPU_SUBTYPE_X86_PENTIUM_3_XEON,
  CPU_SUBTYPE_X86_PENTIUM_4,
  CPU_SUBTYPE_X86_ITANIUM,
  CPU_SUBTYPE_X86_ITANIUM_2,
  CPU_SUBTYPE_X86_XEON,
  CPU_SUBTYPE_X86_XEON_MP,
  CPU_SUBTYPE_X86_LAST,
} cpu_subtype_x86_t;
static_assert(sizeof(cpu_subtype_x86_t) == sizeof(int32_t));

#endif /* CPU_SUBTYPE_H */