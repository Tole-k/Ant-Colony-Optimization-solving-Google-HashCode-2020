# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /home/anatol/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/anatol/.local/share/JetBrains/Toolbox/apps/clion/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anatol/Documents/GitHub/Mroovy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anatol/Documents/GitHub/Mroovy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: /home/anatol/Documents/GitHub/Mroovy/main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anatol/Documents/GitHub/Mroovy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/anatol/Documents/GitHub/Mroovy/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anatol/Documents/GitHub/Mroovy/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anatol/Documents/GitHub/Mroovy/main.cpp -o CMakeFiles/main.dir/main.cpp.s

CMakeFiles/main.dir/Library.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Library.cpp.o: /home/anatol/Documents/GitHub/Mroovy/Library.cpp
CMakeFiles/main.dir/Library.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anatol/Documents/GitHub/Mroovy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/Library.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/Library.cpp.o -MF CMakeFiles/main.dir/Library.cpp.o.d -o CMakeFiles/main.dir/Library.cpp.o -c /home/anatol/Documents/GitHub/Mroovy/Library.cpp

CMakeFiles/main.dir/Library.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Library.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anatol/Documents/GitHub/Mroovy/Library.cpp > CMakeFiles/main.dir/Library.cpp.i

CMakeFiles/main.dir/Library.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Library.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anatol/Documents/GitHub/Mroovy/Library.cpp -o CMakeFiles/main.dir/Library.cpp.s

CMakeFiles/main.dir/AntColonyOptimization.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/AntColonyOptimization.cpp.o: /home/anatol/Documents/GitHub/Mroovy/AntColonyOptimization.cpp
CMakeFiles/main.dir/AntColonyOptimization.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anatol/Documents/GitHub/Mroovy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/AntColonyOptimization.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/AntColonyOptimization.cpp.o -MF CMakeFiles/main.dir/AntColonyOptimization.cpp.o.d -o CMakeFiles/main.dir/AntColonyOptimization.cpp.o -c /home/anatol/Documents/GitHub/Mroovy/AntColonyOptimization.cpp

CMakeFiles/main.dir/AntColonyOptimization.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/AntColonyOptimization.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anatol/Documents/GitHub/Mroovy/AntColonyOptimization.cpp > CMakeFiles/main.dir/AntColonyOptimization.cpp.i

CMakeFiles/main.dir/AntColonyOptimization.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/AntColonyOptimization.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anatol/Documents/GitHub/Mroovy/AntColonyOptimization.cpp -o CMakeFiles/main.dir/AntColonyOptimization.cpp.s

CMakeFiles/main.dir/Ant.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/Ant.cpp.o: /home/anatol/Documents/GitHub/Mroovy/Ant.cpp
CMakeFiles/main.dir/Ant.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anatol/Documents/GitHub/Mroovy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/Ant.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/Ant.cpp.o -MF CMakeFiles/main.dir/Ant.cpp.o.d -o CMakeFiles/main.dir/Ant.cpp.o -c /home/anatol/Documents/GitHub/Mroovy/Ant.cpp

CMakeFiles/main.dir/Ant.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/Ant.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anatol/Documents/GitHub/Mroovy/Ant.cpp > CMakeFiles/main.dir/Ant.cpp.i

CMakeFiles/main.dir/Ant.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/Ant.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anatol/Documents/GitHub/Mroovy/Ant.cpp -o CMakeFiles/main.dir/Ant.cpp.s

CMakeFiles/main.dir/GreedyAnt.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/GreedyAnt.cpp.o: /home/anatol/Documents/GitHub/Mroovy/GreedyAnt.cpp
CMakeFiles/main.dir/GreedyAnt.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anatol/Documents/GitHub/Mroovy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/GreedyAnt.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/GreedyAnt.cpp.o -MF CMakeFiles/main.dir/GreedyAnt.cpp.o.d -o CMakeFiles/main.dir/GreedyAnt.cpp.o -c /home/anatol/Documents/GitHub/Mroovy/GreedyAnt.cpp

CMakeFiles/main.dir/GreedyAnt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/GreedyAnt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anatol/Documents/GitHub/Mroovy/GreedyAnt.cpp > CMakeFiles/main.dir/GreedyAnt.cpp.i

CMakeFiles/main.dir/GreedyAnt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/GreedyAnt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anatol/Documents/GitHub/Mroovy/GreedyAnt.cpp -o CMakeFiles/main.dir/GreedyAnt.cpp.s

CMakeFiles/main.dir/PheromoneAnt.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/PheromoneAnt.cpp.o: /home/anatol/Documents/GitHub/Mroovy/PheromoneAnt.cpp
CMakeFiles/main.dir/PheromoneAnt.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anatol/Documents/GitHub/Mroovy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/PheromoneAnt.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/PheromoneAnt.cpp.o -MF CMakeFiles/main.dir/PheromoneAnt.cpp.o.d -o CMakeFiles/main.dir/PheromoneAnt.cpp.o -c /home/anatol/Documents/GitHub/Mroovy/PheromoneAnt.cpp

CMakeFiles/main.dir/PheromoneAnt.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/PheromoneAnt.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anatol/Documents/GitHub/Mroovy/PheromoneAnt.cpp > CMakeFiles/main.dir/PheromoneAnt.cpp.i

CMakeFiles/main.dir/PheromoneAnt.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/PheromoneAnt.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anatol/Documents/GitHub/Mroovy/PheromoneAnt.cpp -o CMakeFiles/main.dir/PheromoneAnt.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o" \
"CMakeFiles/main.dir/Library.cpp.o" \
"CMakeFiles/main.dir/AntColonyOptimization.cpp.o" \
"CMakeFiles/main.dir/Ant.cpp.o" \
"CMakeFiles/main.dir/GreedyAnt.cpp.o" \
"CMakeFiles/main.dir/PheromoneAnt.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/main.cpp.o
main: CMakeFiles/main.dir/Library.cpp.o
main: CMakeFiles/main.dir/AntColonyOptimization.cpp.o
main: CMakeFiles/main.dir/Ant.cpp.o
main: CMakeFiles/main.dir/GreedyAnt.cpp.o
main: CMakeFiles/main.dir/PheromoneAnt.cpp.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anatol/Documents/GitHub/Mroovy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/anatol/Documents/GitHub/Mroovy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anatol/Documents/GitHub/Mroovy /home/anatol/Documents/GitHub/Mroovy /home/anatol/Documents/GitHub/Mroovy/cmake-build-debug /home/anatol/Documents/GitHub/Mroovy/cmake-build-debug /home/anatol/Documents/GitHub/Mroovy/cmake-build-debug/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

