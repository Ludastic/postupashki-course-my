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
include tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/compiler_depend.make

# Include the progress variables for this target.
include tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/progress.make

# Include the compile flags for this target's objects.
include tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/flags.make

tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/test.cpp.o: tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/flags.make
tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/test.cpp.o: ../tasks/containers/median_finder/test.cpp
tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/test.cpp.o: tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pudge1000-7/postupashki-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/test.cpp.o"
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/median_finder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/test.cpp.o -MF CMakeFiles/test_median_finder.dir/test.cpp.o.d -o CMakeFiles/test_median_finder.dir/test.cpp.o -c /home/pudge1000-7/postupashki-course/tasks/containers/median_finder/test.cpp

tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_median_finder.dir/test.cpp.i"
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/median_finder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pudge1000-7/postupashki-course/tasks/containers/median_finder/test.cpp > CMakeFiles/test_median_finder.dir/test.cpp.i

tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_median_finder.dir/test.cpp.s"
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/median_finder && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pudge1000-7/postupashki-course/tasks/containers/median_finder/test.cpp -o CMakeFiles/test_median_finder.dir/test.cpp.s

# Object files for target test_median_finder
test_median_finder_OBJECTS = \
"CMakeFiles/test_median_finder.dir/test.cpp.o"

# External object files for target test_median_finder
test_median_finder_EXTERNAL_OBJECTS =

test_median_finder: tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/test.cpp.o
test_median_finder: tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/build.make
test_median_finder: tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pudge1000-7/postupashki-course/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../test_median_finder"
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/median_finder && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_median_finder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/build: test_median_finder
.PHONY : tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/build

tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/clean:
	cd /home/pudge1000-7/postupashki-course/build/tasks/containers/median_finder && $(CMAKE_COMMAND) -P CMakeFiles/test_median_finder.dir/cmake_clean.cmake
.PHONY : tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/clean

tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/depend:
	cd /home/pudge1000-7/postupashki-course/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pudge1000-7/postupashki-course /home/pudge1000-7/postupashki-course/tasks/containers/median_finder /home/pudge1000-7/postupashki-course/build /home/pudge1000-7/postupashki-course/build/tasks/containers/median_finder /home/pudge1000-7/postupashki-course/build/tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tasks/containers/median_finder/CMakeFiles/test_median_finder.dir/depend

