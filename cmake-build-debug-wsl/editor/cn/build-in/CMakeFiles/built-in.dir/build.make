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
include editor/cn/build-in/CMakeFiles/built-in.dir/depend.make

# Include the progress variables for this target.
include editor/cn/build-in/CMakeFiles/built-in.dir/progress.make

# Include the compile flags for this target's objects.
include editor/cn/build-in/CMakeFiles/built-in.dir/flags.make

editor/cn/build-in/CMakeFiles/built-in.dir/ListNode.cpp.o: editor/cn/build-in/CMakeFiles/built-in.dir/flags.make
editor/cn/build-in/CMakeFiles/built-in.dir/ListNode.cpp.o: ../editor/cn/build-in/ListNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object editor/cn/build-in/CMakeFiles/built-in.dir/ListNode.cpp.o"
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/editor/cn/build-in && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/built-in.dir/ListNode.cpp.o -c /mnt/d/code/c-code/leetcode/editor/cn/build-in/ListNode.cpp

editor/cn/build-in/CMakeFiles/built-in.dir/ListNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/built-in.dir/ListNode.cpp.i"
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/editor/cn/build-in && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/code/c-code/leetcode/editor/cn/build-in/ListNode.cpp > CMakeFiles/built-in.dir/ListNode.cpp.i

editor/cn/build-in/CMakeFiles/built-in.dir/ListNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/built-in.dir/ListNode.cpp.s"
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/editor/cn/build-in && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/code/c-code/leetcode/editor/cn/build-in/ListNode.cpp -o CMakeFiles/built-in.dir/ListNode.cpp.s

# Object files for target built-in
built__in_OBJECTS = \
"CMakeFiles/built-in.dir/ListNode.cpp.o"

# External object files for target built-in
built__in_EXTERNAL_OBJECTS =

editor/cn/build-in/libbuilt-in.a: editor/cn/build-in/CMakeFiles/built-in.dir/ListNode.cpp.o
editor/cn/build-in/libbuilt-in.a: editor/cn/build-in/CMakeFiles/built-in.dir/build.make
editor/cn/build-in/libbuilt-in.a: editor/cn/build-in/CMakeFiles/built-in.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbuilt-in.a"
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/editor/cn/build-in && $(CMAKE_COMMAND) -P CMakeFiles/built-in.dir/cmake_clean_target.cmake
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/editor/cn/build-in && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/built-in.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
editor/cn/build-in/CMakeFiles/built-in.dir/build: editor/cn/build-in/libbuilt-in.a

.PHONY : editor/cn/build-in/CMakeFiles/built-in.dir/build

editor/cn/build-in/CMakeFiles/built-in.dir/clean:
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/editor/cn/build-in && $(CMAKE_COMMAND) -P CMakeFiles/built-in.dir/cmake_clean.cmake
.PHONY : editor/cn/build-in/CMakeFiles/built-in.dir/clean

editor/cn/build-in/CMakeFiles/built-in.dir/depend:
	cd /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/code/c-code/leetcode /mnt/d/code/c-code/leetcode/editor/cn/build-in /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/editor/cn/build-in /mnt/d/code/c-code/leetcode/cmake-build-debug-wsl/editor/cn/build-in/CMakeFiles/built-in.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : editor/cn/build-in/CMakeFiles/built-in.dir/depend
