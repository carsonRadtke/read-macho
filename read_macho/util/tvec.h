#include <stdlib.h>

#ifndef TVEC_ID
#error "TVEC_ID definition missing"
#endif /* TVEC_ID */

#ifndef TVEC_ID_LOWER
#undef TVEC_ID
#error "TVEC_ID_LOWER definition missing"
#endif /* TVEC_ID_LOWER */

#ifndef TVEC_TYPE
#undef TVEC_ID
#undef TVEC_ID_LOWER
#error "TVEC_TYPE definition missing"
#endif

typedef struct TVEC_ID(_T) TVEC_ID(_T), * TVEC_ID(T);
struct TVEC_ID(_T)
{
  size_t cap;
  size_t size;
  TVEC_TYPE * data;
};

static size_t TVEC_ID_LOWER(size)(TVEC_ID(T) vec)
{
  return vec->size;
}

static void TVEC_ID_LOWER(open)(TVEC_ID(T) to_open, size_t cap)
{
  to_open->cap = cap;
  to_open->size = 0;
  to_open->data = malloc(sizeof(*(to_open->data)) * cap);
}

static TVEC_ID(T) TVEC_ID_LOWER(new)(size_t cap)
{
  TVEC_ID(T) new_vec = malloc(sizeof(*new_vec));
  TVEC_ID_LOWER(open)(new_vec, cap);
  return new_vec;
};

static void TVEC_ID_LOWER(__ensure_cap)(TVEC_ID(T) vec,  size_t cap)
{
  if (vec->cap >= cap) return;
  /* TODO (@carsonRadtke)*/
  size_t new_cap = vec->cap * 2;
  if (new_cap < cap) new_cap = cap;
  vec->data = realloc(vec->data, new_cap);
}

static void TVEC_ID_LOWER(add)(TVEC_ID(T) vec, TVEC_TYPE data)
{
  TVEC_ID_LOWER(__ensure_cap)(vec, vec->size+1);
  vec->data[vec->size++] = data;
}

static TVEC_TYPE TVEC_ID_LOWER(get)(TVEC_ID(T) vec, size_t idx)
{
  return vec->data[idx];
}

#undef TVEC_ID
#undef TVEC_ID_LOWER
#undef TVEC_TYPE
