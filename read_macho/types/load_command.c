#include "types/load_command.h"
#include "types/load_command_type.h"

#include "util/br.h"

#include <stdio.h>

void load_command_dump(LOAD_COMMAND load_command)
{
  fprintf(stdout, "LOAD_COMMAND: %p\n", load_command);
  fprintf(stdout, "\tcommand_type: %x\n", load_command->command_type);
  fprintf(stdout, "\tcommand_size: %d\n", load_command->command_size);
}

void load_command_read(LOAD_COMMAND load_command, BR br)
{
  BR_CHECK(br_read_i32(br, &load_command->command_type));
  BR_CHECK(br_read_i32(br, &load_command->command_size));
}
