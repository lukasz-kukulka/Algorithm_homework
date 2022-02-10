cmake_minimum_required(VERSION 3.10)

project(module2)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# To avoid downolad gtst, when we have directory with it
# UPDATE THIS PATH IF YOU HAVE GOOGLETESTS IN DIFFRENT DIRECTORY
if (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/../../googletest)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)
else()
    # Download and unpack googletest at configure time
    configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
    if(result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
    endif()
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
    RESULT_VARIABLE result
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
    if(result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
    endif()

    # Add googletest directly to our build. This defines
    # the gtest and gtest_main targets.
    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
    ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
    EXCLUDE_FROM_ALL)
endif()

enable_testing()
# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# To make files visible for tests directory
include_directories("files/")

# Add directory with tests
add_subdirectory(tests)

set(sources_files files/solutions.cc)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(${PROJECT_NAME} files/main.cc ${sources_files})
add_executable(${PROJECT_NAME}-ut tests/test.cc ${sources_files})

target_link_libraries(${PROJECT_NAME}-ut gtest_main)
add_test(NAME module2_test COMMAND ${PROJECT_NAME}-ut)
