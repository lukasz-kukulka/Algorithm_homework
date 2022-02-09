cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 20)
set(tests_source_files test.cc)

add_library(tests ${tests_source_files})