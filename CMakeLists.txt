# CMake build script for mr-io.

project(mr-io)

cmake_minimum_required(VERSION 2.8)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# Add subdirectory for lib.
add_subdirectory(lib)

# Add subdirectory for test.
add_subdirectory(test)
