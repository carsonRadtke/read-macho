#define TVEC_ID(id) INTVEC_ ## id
#define TVEC_ID_LOWER(id) intvec_ ## id
#define TVEC_TYPE int

#include "util/tvec.h"

#include <assert.h>

static void test_open()
{
  INTVEC__T ivec;

  intvec_open(&ivec, 3);
  assert(intvec_size(&ivec) == 0);
}

static void test_new()
{
  INTVEC_T ivec = intvec_new(3);
  assert(intvec_size(ivec) == 0);
}

static void test_add_and_get()
{
  INTVEC__T ivec;

  intvec_open(&ivec, 3);
  intvec_add(&ivec, 1);
  intvec_add(&ivec, 2);
  assert(intvec_size(&ivec) == 2);

  intvec_add(&ivec, 3);
  intvec_add(&ivec, 4);
  assert(intvec_size(&ivec) == 4);

  for (int i = 0; i < 4; i++)
  {
    assert(intvec_get(&ivec, i) == i+1);
  }
}

int main()
{
  test_open();
  test_new();
  test_add_and_get();
  return 0;
}