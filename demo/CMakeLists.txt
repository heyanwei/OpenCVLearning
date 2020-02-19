cmake_minimum_required(VERSION 2.8)

project(demo)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fPIC")

find_package(OpenCV REQUIRED)
message(${OpenCV_INCLUDE_DIRS})
message(${OpenCV_LIBS})

add_definitions(-D ELPP_THREAD_SAFE)
add_definitions(-D DATE_ROLL_BACK_LOG)
add_definitions(-D ISCONSOLE)

aux_source_directory(. DIRSRCS)
include_directories(${OpenCV_INCLUDE_DIRS}  ./imageProc ./camera ./utils/log ./)
add_subdirectory(imageProc)
add_subdirectory(camera)
add_subdirectory(utils)

add_executable(demo ${DIRSRCS})
target_link_libraries(demo ${OpenCV_LIBS} imageproc camera utils)