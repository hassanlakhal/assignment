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
CMAKE_SOURCE_DIR = /home/hassan/Desktop/assignment

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hassan/Desktop/assignment/build

# Include any dependencies generated for this target.
include CMakeFiles/DeribitTradingSystem.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/DeribitTradingSystem.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/DeribitTradingSystem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DeribitTradingSystem.dir/flags.make

CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o: CMakeFiles/DeribitTradingSystem.dir/flags.make
CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o: CMakeFiles/DeribitTradingSystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hassan/Desktop/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o -MF CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o.d -o CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o -c /home/hassan/Desktop/assignment/src/main.cpp

CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hassan/Desktop/assignment/src/main.cpp > CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.i

CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hassan/Desktop/assignment/src/main.cpp -o CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.s

CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o: CMakeFiles/DeribitTradingSystem.dir/flags.make
CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o: ../src/DeribitClient.cpp
CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o: CMakeFiles/DeribitTradingSystem.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hassan/Desktop/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o -MF CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o.d -o CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o -c /home/hassan/Desktop/assignment/src/DeribitClient.cpp

CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hassan/Desktop/assignment/src/DeribitClient.cpp > CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.i

CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hassan/Desktop/assignment/src/DeribitClient.cpp -o CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.s

# Object files for target DeribitTradingSystem
DeribitTradingSystem_OBJECTS = \
"CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o" \
"CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o"

# External object files for target DeribitTradingSystem
DeribitTradingSystem_EXTERNAL_OBJECTS =

DeribitTradingSystem: CMakeFiles/DeribitTradingSystem.dir/src/main.cpp.o
DeribitTradingSystem: CMakeFiles/DeribitTradingSystem.dir/src/DeribitClient.cpp.o
DeribitTradingSystem: CMakeFiles/DeribitTradingSystem.dir/build.make
DeribitTradingSystem: CMakeFiles/DeribitTradingSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hassan/Desktop/assignment/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable DeribitTradingSystem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DeribitTradingSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DeribitTradingSystem.dir/build: DeribitTradingSystem
.PHONY : CMakeFiles/DeribitTradingSystem.dir/build

CMakeFiles/DeribitTradingSystem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DeribitTradingSystem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DeribitTradingSystem.dir/clean

CMakeFiles/DeribitTradingSystem.dir/depend:
	cd /home/hassan/Desktop/assignment/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hassan/Desktop/assignment /home/hassan/Desktop/assignment /home/hassan/Desktop/assignment/build /home/hassan/Desktop/assignment/build /home/hassan/Desktop/assignment/build/CMakeFiles/DeribitTradingSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DeribitTradingSystem.dir/depend
