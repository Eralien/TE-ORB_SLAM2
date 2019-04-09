cmake_minimum_required (VERSION 3.1)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE Debug)

Project ( SEMANTIC_ORBS )

###### Detect Executable ######
find_package(OpenCV REQUIRED )
set( PARSER_SRC
  src/detection.cpp
  src/parser.cpp
  src/run.cpp
)

set( PARSER_HEADERS       
  include/detection.hpp
  include/parser.hpp
)

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( detect ${PARSER_SRC} ${PARSER_HEADERS} )
target_link_libraries( detect )

###### Semantic Executable ######
set( SEMANTIC_SRC
  src/detection.cpp
  src/parser.cpp
  src/classprob.cpp
  src/semantic.cpp
)

set( SEMANTIC_HEADERS       
  include/detection.hpp
  include/parser.hpp
  include/classprob.hpp
  include/semantic.hpp
)

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( semantic ${SEMANTIC_SRC} ${SEMANTIC_HEADERS} )
target_link_libraries( semantic ${OpenCV_LIBS} )

###### Analytic Executable ######
set( ANALYTIC_SRC
  src/detection.cpp
  src/parser.cpp
  src/analytics.cpp
)

set( ANALYTIC_HEADERS       
  include/detection.hpp
  include/parser.hpp
  include/analytics.hpp
)

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( analytic ${ANALYTIC_SRC} ${ANALYTIC_HEADERS} )
target_link_libraries( analytic )
