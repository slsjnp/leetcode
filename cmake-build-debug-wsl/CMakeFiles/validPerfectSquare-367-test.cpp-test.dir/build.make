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
CMAKE_SOURCE_DIR = /mnt/d/code/leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/code/leetcode/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/flags.make

CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.o: CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/flags.make
CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.o: ../editor/cn/validPerfectSquare-367-test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/code/leetcode/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.o -c /mnt/d/code/leetcode/editor/cn/validPerfectSquare-367-test.cpp

CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/code/leetcode/editor/cn/validPerfectSquare-367-test.cpp > CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.i

CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/code/leetcode/editor/cn/validPerfectSquare-367-test.cpp -o CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.s

# Object files for target validPerfectSquare-367-test.cpp-test
validPerfectSquare__367__test_cpp__test_OBJECTS = \
"CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.o"

# External object files for target validPerfectSquare-367-test.cpp-test
validPerfectSquare__367__test_cpp__test_EXTERNAL_OBJECTS =

validPerfectSquare-367-test.cpp-test: CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/editor/cn/validPerfectSquare-367-test.cpp.o
validPerfectSquare-367-test.cpp-test: CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/build.make
validPerfectSquare-367-test.cpp-test: editor/cn/build-in/libbuilt-in.a
validPerfectSquare-367-test.cpp-test: CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/code/leetcode/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable validPerfectSquare-367-test.cpp-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/build: validPerfectSquare-367-test.cpp-test

.PHONY : CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/build

CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/clean

CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/depend:
	cd /mnt/d/code/leetcode/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/code/leetcode /mnt/d/code/leetcode /mnt/d/code/leetcode/cmake-build-debug-wsl /mnt/d/code/leetcode/cmake-build-debug-wsl /mnt/d/code/leetcode/cmake-build-debug-wsl/CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/validPerfectSquare-367-test.cpp-test.dir/depend

