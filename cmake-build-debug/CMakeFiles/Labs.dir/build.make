# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gvdozd/Projects/Labs

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gvdozd/Projects/Labs/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Labs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Labs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Labs.dir/flags.make

CMakeFiles/Labs.dir/main.cpp.o: CMakeFiles/Labs.dir/flags.make
CMakeFiles/Labs.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gvdozd/Projects/Labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Labs.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Labs.dir/main.cpp.o -c /Users/gvdozd/Projects/Labs/main.cpp

CMakeFiles/Labs.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Labs.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gvdozd/Projects/Labs/main.cpp > CMakeFiles/Labs.dir/main.cpp.i

CMakeFiles/Labs.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Labs.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gvdozd/Projects/Labs/main.cpp -o CMakeFiles/Labs.dir/main.cpp.s

# Object files for target Labs
Labs_OBJECTS = \
"CMakeFiles/Labs.dir/main.cpp.o"

# External object files for target Labs
Labs_EXTERNAL_OBJECTS =

Labs: CMakeFiles/Labs.dir/main.cpp.o
Labs: CMakeFiles/Labs.dir/build.make
Labs: CMakeFiles/Labs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gvdozd/Projects/Labs/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Labs"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Labs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Labs.dir/build: Labs

.PHONY : CMakeFiles/Labs.dir/build

CMakeFiles/Labs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Labs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Labs.dir/clean

CMakeFiles/Labs.dir/depend:
	cd /Users/gvdozd/Projects/Labs/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gvdozd/Projects/Labs /Users/gvdozd/Projects/Labs /Users/gvdozd/Projects/Labs/cmake-build-debug /Users/gvdozd/Projects/Labs/cmake-build-debug /Users/gvdozd/Projects/Labs/cmake-build-debug/CMakeFiles/Labs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Labs.dir/depend

