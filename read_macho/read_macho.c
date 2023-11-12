#include "types/macho_header.h"
#include "types/load_command.h"

#include "types/segment_section_type.h"
#include "util/br.h"

#include <assert.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
  assert(argc == 2);

  _BR br;
  _MACHO_HEADER header;

  BR_CHECK(br_open(&br, argv[1]));
  macho_header_read(&header, &br);
  macho_header_dump(&header);
  BR_CHECK(br_close(&br));
  
  return 0;
}
