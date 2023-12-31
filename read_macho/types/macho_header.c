#include "types/macho_header.h"

#include <assert.h>
#include <stdio.h>

void macho_header_dump(MACHO_HEADER header)
{
  fprintf(stdout, "MACHO_HEADER: %p\n", header);
  fprintf(stdout, "\tmagic_number: %x\n", header->magic_number);
  fprintf(stdout, "\tcpu_type: %x\n", header->cpu_type);
  fprintf(stdout, "\tcpu_subtype: %x\n", header->cpu_subtype);
  fprintf(stdout, "\tfile_type: %x\n", header->file_type);
  fprintf(stdout, "\tnumber_of_load_commands: %d\n", header->number_of_load_commands);
  fprintf(stdout, "\tsize_of_load_commands: %d\n", header->size_of_load_commands);
  fprintf(stdout, "\tflags: %x\n", header->flags);
  fprintf(stdout, "\treserved: %d\n", header->reserved);

  for (int i = 0; i < header->number_of_load_commands; i++)
  {
    load_command_dump(load_commandvec_getptr(&header->load_commands, i));
  }
}

void macho_header_read(MACHO_HEADER header, BR br)
{
  BR_CHECK(br_read_u32(br, &header->magic_number));
  BR_CHECK(br_read_i32(br, (int32_t*)&header->cpu_type));
  BR_CHECK(br_read_i32(br, (int32_t*)&header->cpu_subtype));
  BR_CHECK(br_read_i32(br, (int32_t*)&header->file_type));
  BR_CHECK(br_read_i32(br, &header->number_of_load_commands));
  BR_CHECK(br_read_i32(br, &header->size_of_load_commands));
  BR_CHECK(br_read_i32(br, &header->flags));
  BR_CHECK(br_read_i32(br, &header->reserved));

  load_commandvec_open(&header->load_commands, header->number_of_load_commands);
  for (int i = 0; i < header->number_of_load_commands; i++)
  {
    _LOAD_COMMAND to_add;
    load_command_read(&to_add, br);
    load_commandvec_add(&header->load_commands, to_add);
  }
}
