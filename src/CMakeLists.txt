# This file is part of BAPS.
# BAPS is licenced under MIT License. See LICENSE.txt for more details.

IF(BAPS_DONE_TOP_LEVEL_CMAKE)
ELSE()
  message(FATAL_ERROR "Please run cmake in the top-level directory, not this one.")
ENDIF()

SET(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_AUTOMOC ON)

SET(FP ${CMAKE_SOURCE_DIR}/src)
FILE(GLOB SRCS
  ${FP}/baps.cpp
  ${FP}/server.cpp
  ${FP}/command.cpp
  ${FP}/server.h
  ${FP}/util.h
  ${FP}/command.h
)

# Find Qt5Network
FIND_PACKAGE(Qt5Network REQUIRED)
include_directories(${Qt5Network_INCLUDE_DIRS})
add_definitions(${Qt5Network_DEFINITIONS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Network_EXECUTABLE_COMPILE_FLAGS}")

# Set other flags
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -g -Wall")

# TODO: Not use relative file paths so much
ADD_EXECUTABLE(baps ${SRCS})

target_link_libraries(baps ${Qt5Network_LIBRARIES})

