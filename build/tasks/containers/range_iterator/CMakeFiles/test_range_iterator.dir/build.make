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
CMAKE_SOURCE_DIR = /home/pudge1000-7/postupashki-course

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pudge1000-7/postupashki-course/build

# Include any dependencies generated for this target.
include tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/flags.make

tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/test.cpp.o: tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/flags.make
tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/test.cpp.o: ../tasks/containers/range_iterator/test.cpp
tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/test.cpp.o: tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pudge1000-7/postupashki-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/test.cpp.o"
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/range_iterator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/test.cpp.o -MF CMakeFiles/test_range_iterator.dir/test.cpp.o.d -o CMakeFiles/test_range_iterator.dir/test.cpp.o -c /home/pudge1000-7/postupashki-course/tasks/containers/range_iterator/test.cpp

tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_range_iterator.dir/test.cpp.i"
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/range_iterator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pudge1000-7/postupashki-course/tasks/containers/range_iterator/test.cpp > CMakeFiles/test_range_iterator.dir/test.cpp.i

tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_range_iterator.dir/test.cpp.s"
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/range_iterator && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pudge1000-7/postupashki-course/tasks/containers/range_iterator/test.cpp -o CMakeFiles/test_range_iterator.dir/test.cpp.s

# Object files for target test_range_iterator
test_range_iterator_OBJECTS = \
"CMakeFiles/test_range_iterator.dir/test.cpp.o"

# External object files for target test_range_iterator
test_range_iterator_EXTERNAL_OBJECTS =

test_range_iterator: tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/test.cpp.o
test_range_iterator: tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/build.make
test_range_iterator: /usr/local/lib/libCatch2Main.a
test_range_iterator: /usr/local/lib/libCatch2.a
test_range_iterator: tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pudge1000-7/postupashki-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../test_range_iterator"
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/range_iterator && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_range_iterator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/build: test_range_iterator
.PHONY : tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/build

tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/clean:
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/range_iterator && $(CMAKE_COMMAND) -P CMakeFiles/test_range_iterator.dir/cmake_clean.cmake
.PHONY : tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/clean

tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/depend:
	cd /home/pudge1000-7/postupashki-course/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pudge1000-7/postupashki-course /home/pudge1000-7/postupashki-course/tasks/containers/range_iterator /home/pudge1000-7/postupashki-course/build /home/pudge1000-7/postupashki-course/build/tasks/containers/range_iterator /home/pudge1000-7/postupashki-course/build/tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/containers/range_iterator/CMakeFiles/test_range_iterator.dir/depend

