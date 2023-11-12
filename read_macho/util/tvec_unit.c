#define TVEC_ID(id) INTVEC_ ## id
#define TVEC_ID_LOWER(id) intvec_ ## id
#define TVEC_TYPE int

#include "util/tvec.h"

#include <assert.h>

int main()
{
  INTVEC__T ivec;

  intvec_open(&ivec, 3);
  assert(intvec_size(&ivec) == 0);

  return 0;
}