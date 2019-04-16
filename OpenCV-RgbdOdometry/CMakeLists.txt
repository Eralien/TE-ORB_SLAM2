cmake_minimum_required(VERSION 3.1)

project(rgbd-odometry)

#c++11
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()
set(CMAKE_BUILD_TYPE Debug)


#opencv
find_package(OpenCV)
find_package(Eigen3 REQUIRED)

file(GLOB TARGET_SRC
    src/*.cpp
    src/opencv_odometry/*.cpp
)

include_directories(${OpenCV_INCLUDE_DIRS} include)
include_directories(${EIGEN3_INCLUDE_DIR})
add_executable(rgbd-odometry ${TARGET_SRC})
target_link_libraries (rgbd-odometry ${OpenCV_LIBS})
