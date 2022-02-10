cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(tests_source_files test.cc)

INCLUDE_DIRECTORIES(${gtest_SOURCE_DIR}/include ${COMMON_INCLUDES})
add_library(tests ${tests_source_files})