# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/code/c-code/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/code/c-code/leetcode/cmake-build-debug

# Include any dependencies generated for this target.
include _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/depend.make

# Include the progress variables for this target.
include _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/flags.make

_deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o: _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/flags.make
_deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o: _deps/benchmark-src/src/benchmark_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/code/c-code/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o"
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark_main.dir/benchmark_main.cc.o -c /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-src/src/benchmark_main.cc

_deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark_main.dir/benchmark_main.cc.i"
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-src/src/benchmark_main.cc > CMakeFiles/benchmark_main.dir/benchmark_main.cc.i

_deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark_main.dir/benchmark_main.cc.s"
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-src/src/benchmark_main.cc -o CMakeFiles/benchmark_main.dir/benchmark_main.cc.s

# Object files for target benchmark_main
benchmark_main_OBJECTS = \
"CMakeFiles/benchmark_main.dir/benchmark_main.cc.o"

# External object files for target benchmark_main
benchmark_main_EXTERNAL_OBJECTS =

_deps/benchmark-build/src/libbenchmark_main.a: _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o
_deps/benchmark-build/src/libbenchmark_main.a: _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/build.make
_deps/benchmark-build/src/libbenchmark_main.a: _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/code/c-code/leetcode/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbenchmark_main.a"
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-build/src && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_main.dir/cmake_clean_target.cmake
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/build: _deps/benchmark-build/src/libbenchmark_main.a

.PHONY : _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/build

_deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/clean:
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-build/src && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_main.dir/cmake_clean.cmake
.PHONY : _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/clean

_deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/depend:
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/code/c-code/leetcode /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-src/src /mnt/d/code/c-code/leetcode/cmake-build-debug /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-build/src /mnt/d/code/c-code/leetcode/cmake-build-debug/_deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/benchmark-build/src/CMakeFiles/benchmark_main.dir/depend

