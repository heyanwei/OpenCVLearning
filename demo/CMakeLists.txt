cmake_minimum_required(VERSION 2.8)

project(demo)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fPIC")

find_package(OpenCV REQUIRED)

aux_source_directory(. DIRSRCS)
include_directories(${OpenCV_INCLUDE_DIRS}  ./imageProc ./camera ./)
add_subdirectory(imageProc)
add_subdirectory(camera)

add_executable(demo ${DIRSRCS})
target_link_libraries(demo ${OpenCV_LIBS} imageproc camera)