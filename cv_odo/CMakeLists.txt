cmake_minimum_required (VERSION 3.1)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_BUILD_TYPE Debug)

Project ( CV_ODO )

find_package(OpenCV REQUIRED )
find_package(Boost 1.36.0 COMPONENTS filesystem )

set( CV_ODO_SRC 
  src/main.cpp
)

set( CV_ODO_HEADERS  
)


INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
include_directories(${Boost_INCLUDE_DIRS})
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( odo ${CV_ODO_SRC} ${CV_ODO_HEADERS} )
target_link_libraries( odo ${OpenCV_LIBS} ${Boost_LIBRARIES})
