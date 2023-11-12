#ifndef LOAD_COMMAND_TYPE_H
#define LOAD_COMMAND_TYPE_H

#include <stdint.h>

typedef struct _LOAD_COMMAND _LOAD_COMMAND, *LOAD_COMMAND;
struct _LOAD_COMMAND
{
  int32_t command_type;
  int32_t command_size;
};

#endif /* LOAD_COMMAND_TYPE_H */
