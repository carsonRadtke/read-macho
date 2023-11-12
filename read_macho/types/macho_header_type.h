#ifndef MACHO_HEADER_TYPE_H
#define MACHO_HEADER_TYPE_H

#include <stdint.h>

#include "types/load_command.h"

#include "values/cpu_type.h"
#include "values/cpu_subtype_arm.h"
#include "values/file_type.h"
#include "values/flag.h"

#define TVEC_ID(id) LOAD_COMMANDVEC_ ## id
#define TVEC_ID_LOWER(id) load_commandvec_ ## id
#define TVEC_TYPE _LOAD_COMMAND

#include "util/tvec.h"

typedef struct _MACHO_HEADER _MACHO_HEADER, *MACHO_HEADER;
struct _MACHO_HEADER
{
  uint32_t magic_number;
  cpu_type_t cpu_type;
  cpu_subtype_arm_t cpu_subtype;
  file_type_t file_type;
  int32_t number_of_load_commands;
  int32_t size_of_load_commands;
  flag_t flags;
  int32_t reserved;
  LOAD_COMMANDVEC__T load_commands;
};

#endif /* MACHO_HEADER_TYPE_H */
