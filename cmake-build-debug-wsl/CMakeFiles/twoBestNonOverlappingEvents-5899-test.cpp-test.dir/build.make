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
CMAKE_BINARY_DIR = /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl

# Include any dependencies generated for this target.
include CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/flags.make

CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.o: CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/flags.make
CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.o: ../editor/cn/twoBestNonOverlappingEvents-5899-test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.o -c /mnt/d/code/c-code/leetcode/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp

CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/code/c-code/leetcode/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp > CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.i

CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/code/c-code/leetcode/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp -o CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.s

# Object files for target twoBestNonOverlappingEvents-5899-test.cpp-test
twoBestNonOverlappingEvents__5899__test_cpp__test_OBJECTS = \
"CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.o"

# External object files for target twoBestNonOverlappingEvents-5899-test.cpp-test
twoBestNonOverlappingEvents__5899__test_cpp__test_EXTERNAL_OBJECTS =

twoBestNonOverlappingEvents-5899-test.cpp-test: CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/editor/cn/twoBestNonOverlappingEvents-5899-test.cpp.o
twoBestNonOverlappingEvents-5899-test.cpp-test: CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/build.make
twoBestNonOverlappingEvents-5899-test.cpp-test: editor/cn/build-in/libbuilt-in.a
twoBestNonOverlappingEvents-5899-test.cpp-test: CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable twoBestNonOverlappingEvents-5899-test.cpp-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/build: twoBestNonOverlappingEvents-5899-test.cpp-test

.PHONY : CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/build

CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/clean

CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/depend:
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/code/c-code/leetcode /mnt/d/code/c-code/leetcode /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/twoBestNonOverlappingEvents-5899-test.cpp-test.dir/depend
