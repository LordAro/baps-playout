# This file is part of BAPS.
# BAPS is licenced under MIT License. See LICENSE.txt for more details.

PROJECT(BAPS)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)

SET(BAPS_DONE_TOP_LEVEL_CMAKE ON)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

message(STATUS "Generating BAPS build files")
add_subdirectory(src)

GET_TARGET_PROPERTY(BAPS_EXE baps LOCATION)
add_custom_target(run COMMAND ${BAPS_EXE})
add_dependencies(run baps)

# NOTE: Assumes gdb is in path, doesn't (can't) check for it
add_custom_target(gdbrun COMMAND gdb ${BAPS_EXE})
add_dependencies(gdbrun baps)

FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)
  add_custom_target(doc COMMAND ${DOXYGEN_EXECUTABLE})
ENDIF()
