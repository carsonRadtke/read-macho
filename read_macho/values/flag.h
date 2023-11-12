#ifndef FLAG_H
#define FLAG_H

#include <stdint.h>

typedef int32_t flag_t;

static const flag_t FLAG_NO_UNDEFINED_REFERENCES = 1 << 0;
static const flag_t FLAG_OUTPUT_OF_INCREMENTAL_LINK = 1 << 1;
static const flag_t FLAG_INPUT_FOR_DYNAMIC_LINKER = 1 << 2;
static const flag_t FLAG_UNDEFINED_REFERENCES_BOUND_BY_DYNAMIC_LINKER = 1 << 3;
static const flag_t FLAG_DYNAMIC_UNDEFINED_REFERENCES_PREBOUND = 1 << 4;
static const flag_t FILE_SPLIT_READ_ONLY_AND_WRITE_ONLY = 1 << 5;
static const flag_t FLAG_TWO_LEVEL_NAME_SPACE_BINDINGS = 1 << 7;
static const flag_t FLAG_USE_FLAG_NAME_SPACE_BINDINGS = 1 << 8;
static const flag_t FLAG_NO_MULTIPLE_DEFINITIONS = 1 << 9;
static const flag_t FLAG_NO_DYLD_NOTIFY = 1 << 10;
static const flag_t FLAG_NOT_YET_PREBOUND = 1 << 11;
static const flag_t FLAG_BINDS_ALL_TWO_LEVEL_NAMESPACES = 1 << 12;
static const flag_t FLAG_SAFE_TO_DIVIDE_INTO_SUBSECTIONS = 1 << 13;
static const flag_t FLAG_CANONICALIZED_BINARY = 1 << 14;
static const flag_t FLAG_CONTAINS_EXTERNAL_WEAK_SYMBOLS = 1 << 15;
static const flag_t FLAG_CONTAINS_WEEK_SYMBOLS = 1 << 16;
static const flag_t FLAG_HAS_STACK_EXECUTION_PRIV = 1 << 17;
static const flag_t FLAG_IS_SAFE_FOR_USE_WITH_UID_ZERO = 1 << 18;
static const flag_t FLAG_IS_SAFE_FOR_UGID_TRUE = 1 << 19;
static const flag_t FLAG_STATIC_LINKER_DO_NOT_EXAMINE_DEPENDENT_DYLIBS = 1 << 20;
static const flag_t FLAG_OS_LOAD_AT_RANDOM_ADDRESS = 1 << 21;
static const flag_t FLAG_STATIC_LINKER_DO_NOT_CREATE_LOAD_COMMAND = 1 << 22;
static const flag_t FLAG_CONTAINS_S_THREAD_LOCAL_VARIABLES = 1 << 23;
static const flag_t FLAG_OS_EXEC_NON_EXECUTABLE_HEAP = 1 << 24;
static const flag_t FLAG_LINKED_FOR_APPLICATION = 1 << 25;
static const flag_t FLAG_NLIST_DIFFERENT_FROM_DYLD_INFO = 1 << 26;
static const flag_t FLAG_ALLOW_LOC_MIN_VERSION_MACOS = 1 << 27;
static const flag_t FLAG_DYLIBS_ONLY = 1 << 31;

#endif /* FLAG_H */