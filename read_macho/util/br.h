#ifndef BR_H
#define BR_H

#include "br_type.h"

#include <stdlib.h>
#include <stdint.h>

#define BR_CHECK(expr)  \
do {                                \
  if (expr != BR_SUCCESS) abort();  \
} while (0)

typedef enum [[nodiscard]] br_result
{
  BR_SUCCESS,
  BR_OPEN_FAILED,
  BR_READ_FAILED,
  BR_CLOSE_FAILED,
} br_result_t;

br_result_t br_open(BR br, const char * file);

br_result_t br_read_cstr(BR br, char * cstr, int size);
br_result_t br_read_i32(BR br, int32_t * i32);
br_result_t br_read_i64(BR br, int64_t * i64);
br_result_t br_read_u32(BR br, uint32_t * i32);

br_result_t br_close(BR br);

#endif /* BR_H */
