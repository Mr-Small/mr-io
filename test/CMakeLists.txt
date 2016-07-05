cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE (GTest)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(mriotest
    mrlock_test.cpp
    mrfile_test.cpp)

target_link_libraries(mriotest
    ${GTEST_BOTH_LIBRARIES}
    mr-io
)

enable_testing()
add_test(A mriotest)
