# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/bartosz/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4694.4/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/bartosz/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/171.4694.4/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bartosz/CLionProjects/Lab8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bartosz/CLionProjects/Lab8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab8.dir/flags.make

CMakeFiles/Lab8.dir/main.cpp.o: CMakeFiles/Lab8.dir/flags.make
CMakeFiles/Lab8.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartosz/CLionProjects/Lab8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab8.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab8.dir/main.cpp.o -c /home/bartosz/CLionProjects/Lab8/main.cpp

CMakeFiles/Lab8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab8.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartosz/CLionProjects/Lab8/main.cpp > CMakeFiles/Lab8.dir/main.cpp.i

CMakeFiles/Lab8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab8.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartosz/CLionProjects/Lab8/main.cpp -o CMakeFiles/Lab8.dir/main.cpp.s

CMakeFiles/Lab8.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Lab8.dir/main.cpp.o.requires

CMakeFiles/Lab8.dir/main.cpp.o.provides: CMakeFiles/Lab8.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Lab8.dir/build.make CMakeFiles/Lab8.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Lab8.dir/main.cpp.o.provides

CMakeFiles/Lab8.dir/main.cpp.o.provides.build: CMakeFiles/Lab8.dir/main.cpp.o


# Object files for target Lab8
Lab8_OBJECTS = \
"CMakeFiles/Lab8.dir/main.cpp.o"

# External object files for target Lab8
Lab8_EXTERNAL_OBJECTS =

Lab8: CMakeFiles/Lab8.dir/main.cpp.o
Lab8: CMakeFiles/Lab8.dir/build.make
Lab8: CMakeFiles/Lab8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bartosz/CLionProjects/Lab8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab8.dir/build: Lab8

.PHONY : CMakeFiles/Lab8.dir/build

CMakeFiles/Lab8.dir/requires: CMakeFiles/Lab8.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Lab8.dir/requires

CMakeFiles/Lab8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab8.dir/clean

CMakeFiles/Lab8.dir/depend:
	cd /home/bartosz/CLionProjects/Lab8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bartosz/CLionProjects/Lab8 /home/bartosz/CLionProjects/Lab8 /home/bartosz/CLionProjects/Lab8/cmake-build-debug /home/bartosz/CLionProjects/Lab8/cmake-build-debug /home/bartosz/CLionProjects/Lab8/cmake-build-debug/CMakeFiles/Lab8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab8.dir/depend

