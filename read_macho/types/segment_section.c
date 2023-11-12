
#include "types/segment_section.h"
#include "types/segment_section_type.h"

#include "util/br.h"

#include <stdio.h>

void segment_section_dump(SEGMENT_SECTION segment_section) {
  fprintf(stdout, "SEGMENT_SECTION: %p\n", segment_section);
  fprintf(stdout, "\tsection_name: %s\n", segment_section->section_name);
  fprintf(stdout, "\tsegment_name: %s\n", segment_section->segment_name);
  fprintf(stdout, "\tsection_address: %llx\n", segment_section->section_address);
  fprintf(stdout, "\tsection_size: %lld\n", segment_section->section_size);
  fprintf(stdout, "\talignment: %d\n", segment_section->alignment);
  fprintf(stdout, "\trelocations_file_offset: %d\n", segment_section->relocations_file_offset);
  fprintf(stdout, "\tnumber_of_relocations: %d\n", segment_section->number_of_relocations);
  fprintf(stdout, "\tflag_type: %d\n", segment_section->flag_type);
  fprintf(stdout, "\treserved1: %d\n", segment_section->reserved1);
  fprintf(stdout, "\treserved2: %d\n", segment_section->reserved2);
  fprintf(stdout, "\treserved3: %d\n", segment_section->reserved3);
}

void segment_section_read(SEGMENT_SECTION segment_section, BR br)
{
  BR_CHECK(br_read_cstr(br, segment_section->section_name, sizeof(segment_section->section_name)));
  BR_CHECK(br_read_cstr(br, segment_section->segment_name, sizeof(segment_section->segment_name)));
  BR_CHECK(br_read_i64(br, &segment_section->section_address));
  BR_CHECK(br_read_i64(br, &segment_section->section_size));
  BR_CHECK(br_read_i32(br, &segment_section->section_file_offset));
  BR_CHECK(br_read_i32(br, &segment_section->alignment));
  BR_CHECK(br_read_i32(br, &segment_section->relocations_file_offset));
  BR_CHECK(br_read_i32(br, &segment_section->number_of_relocations));
  BR_CHECK(br_read_i32(br, &segment_section->flag_type));
  BR_CHECK(br_read_i32(br, &segment_section->reserved1));
  BR_CHECK(br_read_i32(br, &segment_section->reserved2));
  BR_CHECK(br_read_i32(br, &segment_section->reserved3));
}
