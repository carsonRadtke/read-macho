#ifndef SEGMENT_LOAD_COMMAND_H
#define SEGMENT_LOAD_COMMAND_H

#include "types/segment_load_command_type.h"

#include "util/br.h"

void segment_load_command_dump(SEGMENT_LOAD_COMMAND segment_load_command);

void segment_load_command_read(SEGMENT_LOAD_COMMAND segment_load_command, BR br);

#endif /* SEGMENT_LOAD_COMMAND_H */
