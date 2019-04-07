cmake_minimum_required (VERSION 2.6.0)
project(parseYolo)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

if( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )
  add_definitions("-fno-strict-aliasing -Wall")
endif( CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX )

add_executable(parse
  src/detection.cpp
  src/parser.cpp
  src/run.cpp
  include/detection.h
  include/parser.h
)