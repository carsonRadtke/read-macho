#ifndef SEGMENT_LOAD_COMMAND_TYPE_H
#define SEGMENT_LOAD_COMMAND_TYPE_H

#include "types/segment_section_type.h"

#include <stdint.h>

#define TVEC_ID(id) SEGMENT_SECTIONVEC_ ## id
#define TVEC_ID_LOWER(id) segment_sectionvec_ ## id
#define TVEC_TYPE _SEGMENT_SECTION

#include "util/tvec.h"

typedef struct _SEGMENT_LOAD_COMMAND _SEGMENT_LOAD_COMMAND, *SEGMENT_LOAD_COMMAND;
struct _SEGMENT_LOAD_COMMAND
{
  char segment_name[16];
  int64_t address;
  int64_t address_size;
  int64_t file_offset;
  int64_t size;
  int32_t maximum_virtual_memory_protections;
  int32_t initial_virtual_memory_protections;
  int32_t number_of_sections;
  int32_t flag32;
  SEGMENT_SECTIONVEC__T sections;
};

#endif /* SEGMENT_LOAD_COMMAND_TYPE_H */
