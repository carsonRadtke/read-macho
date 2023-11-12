#ifndef SEGMENT_SECTION_TYPE_H
#define SEGMENT_SECTION_TYPE_H

#include <stdint.h>

typedef struct _SEGMENT_SECTION _SEGMENT_SECTION, *SEGMENT_SECTION;
struct _SEGMENT_SECTION
{
  char section_name[16];
  char segment_name[16];
  int64_t section_address;
  int64_t section_size;
  int32_t section_file_offset;
  int32_t alignment;
  int32_t relocations_file_offset;
  int32_t number_of_relocations;
  int32_t flag_type;
  int32_t reserved1;
  int32_t reserved2;
  int32_t reserved3;
};

#endif /* SEGMENT_SECTION_TYPE_H */
