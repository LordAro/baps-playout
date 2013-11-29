# This file is part of BAPS.
# BAPS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, version 2.
# BAPS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with BAPS. If not, see <http://www.gnu.org/licenses/>.

IF(BAPS_DONE_TOP_LEVEL_CMAKE)
ELSE()
  message(FATAL_ERROR "Please run cmake in the top-level directory, not this one.")
ENDIF()

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)

FILE(GLOB SRCS
  ${CMAKE_SOURCE_DIR}/src/*.cpp
  ${CMAKE_SOURCE_DIR}/src/*.h
)

# Find Qt5Network
FIND_PACKAGE(Qt5Network REQUIRED)
include_directories(${Qt5Network_INCLUDE_DIRS})
add_definitions(${Qt5Network_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Network_EXECUTABLE_COMPILE_FLAGS}")

# Set other flags
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -Wall")

# TODO: Not use relative file paths so much
ADD_EXECUTABLE(bin/baps ${SRCS})

target_link_libraries(bin/baps ${Qt5Network_LIBRARIES})

GET_TARGET_PROPERTY(BAPS_EXE baps LOCATION)

