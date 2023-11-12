#ifndef SEGMENT_SECTION_H
#define SEGMENT_SECTION_H

#include "types/segment_section_type.h"

#include "util/br.h"

void segment_section_dump(SEGMENT_SECTION segment_section);

void segment_section_read(SEGMENT_SECTION segment_section, BR br);

#endif /* SEGMENT_SECTION_H */
