cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MATRIX_TWO)

add_executable(${PROJECT_NAME} main.cc)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion -O3)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
