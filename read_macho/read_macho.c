#include "types/macho_header.h"
#include "types/load_command.h"
#include "types/segment_load_command.h"

#include "types/segment_section.h"
#include "types/segment_section_type.h"
#include "util/br.h"

#include <assert.h>
#include <stdio.h>

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
    _SEGMENT_LOAD_COMMAND segment_load_command;
    load_command_read(&load_command, &br);
    load_command_dump(&load_command);
    if (load_command.command_type == 0x19)
    {
        segment_load_command_read(&segment_load_command, &br);
        segment_load_command_dump(&segment_load_command);
        for (int i = 0; i < segment_load_command.number_of_sections; i++)
        {
          _SEGMENT_SECTION segment_section;
          segment_section_read(&segment_section, &br);
          segment_section_dump(&segment_section);
        }
    }
  }
  
  return 0;
}
