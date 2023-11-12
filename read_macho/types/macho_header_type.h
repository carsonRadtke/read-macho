#ifndef MACHO_HEADER_TYPE_H
#define MACHO_HEADER_TYPE_H

#include <stdint.h>

typedef struct _MACHO_HEADER _MACHO_HEADER, *MACHO_HEADER;
struct _MACHO_HEADER
{
  uint32_t magic_number;
  int32_t cpu_type;
  int32_t cpu_subtype;
  int32_t file_type;
  int32_t number_of_load_commands;
  int32_t size_of_load_commands;
  int32_t flags;
  int32_t reserved;
};

#endif /* MACHO_HEADER_TYPE_H */
