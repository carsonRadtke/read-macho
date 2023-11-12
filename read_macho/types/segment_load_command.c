
#include "types/segment_load_command.h"
#include "types/segment_load_command_type.h"

#include <stdio.h>

void segment_load_command_dump(SEGMENT_LOAD_COMMAND segment_load_command)
{
  fprintf(stdout, "SEGMENT_LOAD_COMMAND: %p\n", segment_load_command);
  fprintf(stdout, "\taddress: %llx\n", segment_load_command->address);
  fprintf(stdout, "\taddress_size: %lld\n", segment_load_command->address_size);
  fprintf(stdout, "\tfile_offset: %llx\n", segment_load_command->file_offset);
  fprintf(stdout, "\tsize: %lld\n", segment_load_command->size);
  fprintf(stdout, "\tmaximum_virtual_memory_protections: %d\n", segment_load_command->maximum_virtual_memory_protections);
  fprintf(stdout, "\tinitial_virtual_memory_protections: %d\n", segment_load_command->initial_virtual_memory_protections);
  fprintf(stdout, "\tnumber_of_sections: %d\n", segment_load_command->number_of_sections);
  fprintf(stdout, "\tflag32: %x\n" , segment_load_command->flag32);
}

void segment_load_command_read(SEGMENT_LOAD_COMMAND segment_load_command, BR br)
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
}
