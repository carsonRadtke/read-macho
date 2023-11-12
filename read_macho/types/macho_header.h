#ifndef MACHO_HEADER_H
#define MACHO_HEADER_H

#include "macho_header_type.h"

#include "util/br.h"

void macho_header_dump(MACHO_HEADER header);

void macho_header_read(MACHO_HEADER header, BR br);

#endif /* MACHO_HEADER_H */
