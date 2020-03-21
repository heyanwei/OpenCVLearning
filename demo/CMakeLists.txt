cmake_minimum_required(VERSION 2.8)

project(demo)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fPIC")

find_package(OpenCV REQUIRED)

add_definitions(-D ELPP_THREAD_SAFE)
add_definitions(-D DATE_ROLL_BACK_LOG)
add_definitions(-D ISCONSOLE)

aux_source_directory(. DIRSRCS)
aux_source_directory(utils/log/. DIR_LOG_SRCS)
aux_source_directory(person/interface/. DIR_INTERFACE_SRCS)
aux_source_directory(person/body/. DIR_BODY_SRCS)
aux_source_directory(person/face/. DIR_FACE_SRCS)
aux_source_directory(devices/camera/. DIR_CAMERA_SRCS)
aux_source_directory(devices/vedio/. DIR_VEDIO_SRCS)
aux_source_directory(console/. DIR_CONSOLE_SRCS)

include_directories(
    ${OpenCV_INCLUDE_DIRS}
    ./console
    ./devices/camera
    ./devices/vedio
    ./person/body
    ./person/face
    ./person/interface
    ./utils/log
)

add_executable(
    doit
    ${DIRSRCS}
    ${DIR_LOG_SRCS}
    ${DIR_INTERFACE_SRCS}
    ${DIR_BODY_SRCS}
    ${DIR_FACE_SRCS}
    ${DIR_CAMERA_SRCS}
    ${DIR_VEDIO_SRCS}
    ${DIR_CONSOLE_SRCS}
    )

target_link_libraries(doit ${OpenCV_LIBS})