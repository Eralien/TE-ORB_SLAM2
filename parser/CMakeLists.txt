cmake_minimum_required (VERSION 3.1)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE Debug)

Project ( SEMANTIC_ORBS )

find_package(OpenCV REQUIRED )
set( NAME_SRC
  src/detection.cpp
  src/parser.cpp
  src/run.cpp
)

set( NAME_HEADERS       
  include/detection.h
  include/parser.h
)

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( detect ${NAME_SRC} ${NAME_HEADERS} )
target_link_libraries( detect )
