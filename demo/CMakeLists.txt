cmake_minimum_required(VERSION 2.8)

project(DEMO)

find_package(OpenCV REQUIRED)

aux_source_directory(. DIRSRCS)
include_directories(${OpenCV_INCLUDE_DIRS}  ./imageProc ./)
add_subdirectory(imageProc)

add_executable(demo ${DIRSRCS})
target_link_libraries(demo ${OpenCV_LIBS} imageproc)