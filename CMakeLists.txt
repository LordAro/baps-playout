# This file is part of BAPS.
# BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
# BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.

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
