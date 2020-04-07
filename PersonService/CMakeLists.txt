cmake_minimum_required(VERSION 2.8)

project(PersonService)

find_package(gflags REQUIRED)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -fPIC")

SET(EXENAME person-srv)

SET(GTESTLIB /usr/local/lib/libgtest.a)

aux_source_directory(. DIRSRCS)
aux_source_directory(utils/file/. UFILESRCS)

include_directories(
    ./utils/file
)

add_executable(
    ${EXENAME}
    ${DIRSRCS}
    ${UFILESRCS}
    )
target_link_libraries(${EXENAME} gflags libglog.a ${GTESTLIB})