# CMake build script for mr-io.

project(mr-io)

cmake_minimum_required(VERSION 2.8)

set(SRC
    mrlock.cpp
    mrstream.cpp
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_library(mr-io STATIC
    ${SRC}
)
