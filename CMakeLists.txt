cmake_minimum_required(VERSION 3.21)
project(read_macho)

include_directories(read_macho)

add_library(util OBJECT read_macho/util/br.c)

add_library(
  macho_types
  OBJECT
  read_macho/types/macho_header.c
  read_macho/types/load_command.c
  read_macho/types/macho_header.c
  read_macho/types/segment_section.c
  read_macho/types/segment_load_command.c)

add_executable(
  read_macho
  $<TARGET_OBJECTS:macho_types>
  $<TARGET_OBJECTS:util>
  read_macho/read_macho.c)

set_property(TARGET util PROPERTY C_STANDARD 23)
set_property(TARGET macho_types PROPERTY C_STANDARD 23)
set_property(TARGET read_macho PROPERTY C_STANDARD 23)
