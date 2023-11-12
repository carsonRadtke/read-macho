#include "types/load_command_type.h"

#include "types/segment_section_type.h"
#include "util/br.h"

#include <stdio.h>

static void s_segment_section_dump(SEGMENT_SECTION segment_section)
{
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

static void s_segment_load_command_dump(SEGMENT_LOAD_COMMAND segment_load_command)
{
  fprintf(stdout, "SEGMENT_LOAD_COMMAND: %p\n", segment_load_command);
  fprintf(stdout, "\tsegment_name: %s\n", segment_load_command->segment_name);
  fprintf(stdout, "\taddress: %llx\n", segment_load_command->address);
  fprintf(stdout, "\taddress_size: %lld\n", segment_load_command->address_size);
  fprintf(stdout, "\tfile_offset: %llx\n", segment_load_command->file_offset);
  fprintf(stdout, "\tsize: %lld\n", segment_load_command->size);
  fprintf(stdout, "\tmaximum_virtual_memory_protections: %d\n", segment_load_command->maximum_virtual_memory_protections);
  fprintf(stdout, "\tinitial_virtual_memory_protections: %d\n", segment_load_command->initial_virtual_memory_protections);
  fprintf(stdout, "\tnumber_of_sections: %d\n", segment_load_command->number_of_sections);
  fprintf(stdout, "\tflag32: %x\n" , segment_load_command->flag32);

  for (int i = 0; i < segment_load_command->number_of_sections; i++)
  {
    s_segment_section_dump(segment_sectionvec_getptr(&segment_load_command->sections, i));
  }
}

static void s_segment_section_read(SEGMENT_SECTION segment_section, BR br)
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

static void s_segment_load_command_read(SEGMENT_LOAD_COMMAND segment_load_command, BR br)
{
  BR_CHECK(br_read_cstr(br, segment_load_command->segment_name, sizeof(segment_load_command->segment_name)));
  BR_CHECK(br_read_i64(br, &segment_load_command->address));
  BR_CHECK(br_read_i64(br, &segment_load_command->address_size));
  BR_CHECK(br_read_i64(br, &segment_load_command->file_offset));
  BR_CHECK(br_read_i64(br, &segment_load_command->size));
  BR_CHECK(br_read_i32(br, &segment_load_command->maximum_virtual_memory_protections));
  BR_CHECK(br_read_i32(br, &segment_load_command->initial_virtual_memory_protections));
  BR_CHECK(br_read_i32(br, &segment_load_command->number_of_sections));
  BR_CHECK(br_read_i32(br, &segment_load_command->flag32));

  segment_sectionvec_open(&segment_load_command->sections, segment_load_command->number_of_sections);
  for (int i = 0; i < segment_load_command->number_of_sections; i++)
  {
    _SEGMENT_SECTION segment_section;
    s_segment_section_read(&segment_section, br);
    segment_sectionvec_add(&segment_load_command->sections, segment_section);
  }
}

void load_command_dump(LOAD_COMMAND load_command)
{
  fprintf(stdout, "LOAD_COMMAND: %p\n", load_command);
  fprintf(stdout, "\tcommand_type: %x\n", load_command->command_type);
  fprintf(stdout, "\tcommand_size: %d\n", load_command->command_size);
  switch (load_command->command_type)
  {
    case 0x19:
      s_segment_load_command_dump(&load_command->_.segment);
      break;
    default:
      fprintf(stderr, "unknown command type: %x\n", load_command->command_type);
      break;
  }
}

void load_command_read(LOAD_COMMAND load_command, BR br)
{
  BR_CHECK(br_read_i32(br, &load_command->command_type));
  BR_CHECK(br_read_i32(br, &load_command->command_size));
  switch (load_command->command_type)
  {
    case 0x19:
      s_segment_load_command_read(&load_command->_.segment, br);
      break;
    default:
      fprintf(stderr, "unknown command type: %x\n", load_command->command_type);
      break;
  }
}
