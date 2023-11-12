#include "util/br.h"
#include "types/macho_header.h"
#include "types/load_command.h"
#include "types/segment_load_command.h"

#include <assert.h>

int main(int argc, const char * argv[])
{
  assert(argc == 2);
  const char * bin = argv[1];

  _MACHO_HEADER header;
  _BR br;

  BR_CHECK(br_open(&br, bin));
  macho_header_read(&header, &br);
  macho_header_dump(&header);
  for(int32_t i = 0; i < header.number_of_load_commands; i++) {
    _LOAD_COMMAND load_command;
    load_command_read(&load_command, &br);
    load_command_dump(&load_command);
    if (load_command.command_type == 19) {
      _SEGMENT_LOAD_COMMAND segment_load_command;
      segment_load_command_read(&segment_load_command, &br);
      segment_load_command_dump(&segment_load_command);
    }
  }
  

  return 0;
}
