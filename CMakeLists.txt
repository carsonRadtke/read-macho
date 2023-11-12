cmake_minimum_required(VERSION 3.21)
project(read_macho)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

include_directories(read_macho)

add_library(
  util
  OBJECT
  read_macho/util/br.c)

add_library(
  macho_types
  OBJECT
  read_macho/types/macho_header.c
  read_macho/types/load_command.c)

add_executable(
  read_macho
  $<TARGET_OBJECTS:macho_types>
  $<TARGET_OBJECTS:util>
  read_macho/read_macho.c)

add_executable(br_unit read_macho/util/br_unit.c)
add_test(NAME br_unit COMMAND br_unit)

add_executable(tvec_unit read_macho/util/tvec_unit.c)
add_test(NAME tvec_unit COMMAND tvec_unit)

set_property(TARGET br_unit PROPERTY C_STANDARD 23)
set_property(TARGET tvec_unit PROPERTY C_STANDARD 23)
set_property(TARGET util PROPERTY C_STANDARD 23)
set_property(TARGET macho_types PROPERTY C_STANDARD 23)
set_property(TARGET read_macho PROPERTY C_STANDARD 23)
