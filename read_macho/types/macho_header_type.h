#ifndef MACHO_HEADER_TYPE_H
#define MACHO_HEADER_TYPE_H

#include <stdint.h>

#include "values/cpu_type.h"
#include "values/cpu_subtype_arm.h"
#include "values/file_type.h"

typedef struct _MACHO_HEADER _MACHO_HEADER, *MACHO_HEADER;
struct _MACHO_HEADER
{
  uint32_t magic_number;
  cpu_type_t cpu_type;
  cpu_subtype_arm_t cpu_subtype;
  file_type_t file_type;
  int32_t number_of_load_commands;
  int32_t size_of_load_commands;
  int32_t flags;
  int32_t reserved;
};

#endif /* MACHO_HEADER_TYPE_H */
