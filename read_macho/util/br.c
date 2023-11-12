#include "br.h"

#include <assert.h>
#include <fcntl.h>
#include <unistd.h>

br_result_t br_open(BR br, const char * file)
{
  br->fd = open(file, O_RDONLY);
  if (!br->fd)
  {
    return BR_OPEN_FAILED;
  }
  return BR_SUCCESS;
}

br_result_t br_read_cstr(BR br, char * cstr, int size)
{
  int bytes = read(br->fd, cstr, size);
  if (bytes != size)
  {
    return BR_READ_FAILED;
  }
  return BR_SUCCESS;
}

br_result_t br_read_i32(BR br, int32_t * i32)
{
  int bytes = read(br->fd, i32, sizeof(*i32));
  if (bytes != sizeof(*i32))
  {
    return BR_READ_FAILED;
  }
  return BR_SUCCESS;
}

br_result_t br_read_i64(BR br, int64_t * i64)
{
  int bytes = read(br->fd, i64, sizeof(*i64));
  if (bytes != sizeof(*i64))
  {
    return BR_READ_FAILED;
  }
  return BR_SUCCESS;
}

br_result_t br_read_u32(BR br, uint32_t * u32)
{
  return br_read_i32(br, (int32_t*)u32);
}

br_result_t br_close(BR br)
{
  if (close(br->fd))
  {
    return BR_CLOSE_FAILED;
  }
  return BR_SUCCESS;
}
