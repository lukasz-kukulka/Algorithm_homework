# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/build

# Include any dependencies generated for this target.
include CMakeFiles/MATRIX.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MATRIX.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MATRIX.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MATRIX.dir/flags.make

CMakeFiles/MATRIX.dir/main.cpp.o: CMakeFiles/MATRIX.dir/flags.make
CMakeFiles/MATRIX.dir/main.cpp.o: ../main.cpp
CMakeFiles/MATRIX.dir/main.cpp.o: CMakeFiles/MATRIX.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MATRIX.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MATRIX.dir/main.cpp.o -MF CMakeFiles/MATRIX.dir/main.cpp.o.d -o CMakeFiles/MATRIX.dir/main.cpp.o -c /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/main.cpp

CMakeFiles/MATRIX.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MATRIX.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/main.cpp > CMakeFiles/MATRIX.dir/main.cpp.i

CMakeFiles/MATRIX.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MATRIX.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/main.cpp -o CMakeFiles/MATRIX.dir/main.cpp.s

# Object files for target MATRIX
MATRIX_OBJECTS = \
"CMakeFiles/MATRIX.dir/main.cpp.o"

# External object files for target MATRIX
MATRIX_EXTERNAL_OBJECTS =

MATRIX: CMakeFiles/MATRIX.dir/main.cpp.o
MATRIX: CMakeFiles/MATRIX.dir/build.make
MATRIX: CMakeFiles/MATRIX.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MATRIX"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MATRIX.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MATRIX.dir/build: MATRIX
.PHONY : CMakeFiles/MATRIX.dir/build

CMakeFiles/MATRIX.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MATRIX.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MATRIX.dir/clean

CMakeFiles/MATRIX.dir/depend:
	cd /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/build /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/build /home/lukasz_k/Dokumenty/Programing/Algorithm_homework/matrixs/build/CMakeFiles/MATRIX.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MATRIX.dir/depend

