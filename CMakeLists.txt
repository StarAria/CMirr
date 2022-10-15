cmake_minimum_required (VERSION 2.8.11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON )
set (CMAKE_VERBOSE_MAKEFILE ON)

set(PROJECT_NAME "CMirr")
project(${PROJECT_NAME})


# output path
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)


#Print out the used build type
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "-std=c++14")
# set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -fopenmp")
# set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fno-inline ")
# set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -frename-registers -fprofile-use -fprofile-correction") 
# set(CMAKE_CXX_FLAGS_PROFILE "-Ofast -pg -Winline")
# set(CMAKE_EXE_LINKER_FLAGS "-pthread")

include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

file (GLOB SOURCES
    src/*
    src/parser/*
    src/db/*
    src/global/*
    # src/MirrExt/*
    src/main/*
)

add_executable(${PROJECT_NAME} ${SOURCES})

# file (GLOB EXE_SOURCES src/main.cpp)

# add_executable(${PROJECT_NAME} ${SOURCES} ${EXE_SOURCES})


