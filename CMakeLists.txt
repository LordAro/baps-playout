# This file is part of BAPS.
# BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
# BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.

PROJECT(BAPS)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

FILE(GLOB SRCS
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
)

# TODO: Not use relative file paths so much
ADD_EXECUTABLE(bin/baps ${SRCS})

GET_TARGET_PROPERTY(BAPS_EXE baps LOCATION)
add_custom_target(run COMMAND ${BAPS_EXE})
