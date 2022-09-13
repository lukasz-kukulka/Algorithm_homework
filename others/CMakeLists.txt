cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(solutions)
target_sources( solutions PRIVATE solutions.cc )

project(OTHERS)

target_include_directories(solutions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.cc)
target_link_libraries(${PROJECT_NAME} solutions)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion -O3)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
