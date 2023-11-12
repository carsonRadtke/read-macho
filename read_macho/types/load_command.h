#ifndef LOAD_COMMAND_H
#define LOAD_COMMAND_H

#include "types/load_command_type.h"

#include "util/br.h"

void load_command_dump(LOAD_COMMAND load_command);
void load_command_read(LOAD_COMMAND load_command, BR br);

#endif /* LOAD_COMMAND_H */
