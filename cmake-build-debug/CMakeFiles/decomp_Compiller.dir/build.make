# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tush17/CLionProjects/decomp_Compiller

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/decomp_Compiller.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/decomp_Compiller.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/decomp_Compiller.dir/flags.make

CMakeFiles/decomp_Compiller.dir/main.c.o: CMakeFiles/decomp_Compiller.dir/flags.make
CMakeFiles/decomp_Compiller.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/decomp_Compiller.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/decomp_Compiller.dir/main.c.o -c /home/tush17/CLionProjects/decomp_Compiller/main.c

CMakeFiles/decomp_Compiller.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/decomp_Compiller.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tush17/CLionProjects/decomp_Compiller/main.c > CMakeFiles/decomp_Compiller.dir/main.c.i

CMakeFiles/decomp_Compiller.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/decomp_Compiller.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tush17/CLionProjects/decomp_Compiller/main.c -o CMakeFiles/decomp_Compiller.dir/main.c.s

CMakeFiles/decomp_Compiller.dir/compiler.c.o: CMakeFiles/decomp_Compiller.dir/flags.make
CMakeFiles/decomp_Compiller.dir/compiler.c.o: ../compiler.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/decomp_Compiller.dir/compiler.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/decomp_Compiller.dir/compiler.c.o -c /home/tush17/CLionProjects/decomp_Compiller/compiler.c

CMakeFiles/decomp_Compiller.dir/compiler.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/decomp_Compiller.dir/compiler.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tush17/CLionProjects/decomp_Compiller/compiler.c > CMakeFiles/decomp_Compiller.dir/compiler.c.i

CMakeFiles/decomp_Compiller.dir/compiler.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/decomp_Compiller.dir/compiler.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tush17/CLionProjects/decomp_Compiller/compiler.c -o CMakeFiles/decomp_Compiller.dir/compiler.c.s

CMakeFiles/decomp_Compiller.dir/pre_reader.c.o: CMakeFiles/decomp_Compiller.dir/flags.make
CMakeFiles/decomp_Compiller.dir/pre_reader.c.o: ../pre_reader.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/decomp_Compiller.dir/pre_reader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/decomp_Compiller.dir/pre_reader.c.o -c /home/tush17/CLionProjects/decomp_Compiller/pre_reader.c

CMakeFiles/decomp_Compiller.dir/pre_reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/decomp_Compiller.dir/pre_reader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/tush17/CLionProjects/decomp_Compiller/pre_reader.c > CMakeFiles/decomp_Compiller.dir/pre_reader.c.i

CMakeFiles/decomp_Compiller.dir/pre_reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/decomp_Compiller.dir/pre_reader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/tush17/CLionProjects/decomp_Compiller/pre_reader.c -o CMakeFiles/decomp_Compiller.dir/pre_reader.c.s

# Object files for target decomp_Compiller
decomp_Compiller_OBJECTS = \
"CMakeFiles/decomp_Compiller.dir/main.c.o" \
"CMakeFiles/decomp_Compiller.dir/compiler.c.o" \
"CMakeFiles/decomp_Compiller.dir/pre_reader.c.o"

# External object files for target decomp_Compiller
decomp_Compiller_EXTERNAL_OBJECTS =

decomp_Compiller: CMakeFiles/decomp_Compiller.dir/main.c.o
decomp_Compiller: CMakeFiles/decomp_Compiller.dir/compiler.c.o
decomp_Compiller: CMakeFiles/decomp_Compiller.dir/pre_reader.c.o
decomp_Compiller: CMakeFiles/decomp_Compiller.dir/build.make
decomp_Compiller: CMakeFiles/decomp_Compiller.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable decomp_Compiller"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/decomp_Compiller.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/decomp_Compiller.dir/build: decomp_Compiller

.PHONY : CMakeFiles/decomp_Compiller.dir/build

CMakeFiles/decomp_Compiller.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/decomp_Compiller.dir/cmake_clean.cmake
.PHONY : CMakeFiles/decomp_Compiller.dir/clean

CMakeFiles/decomp_Compiller.dir/depend:
	cd /home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tush17/CLionProjects/decomp_Compiller /home/tush17/CLionProjects/decomp_Compiller /home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug /home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug /home/tush17/CLionProjects/decomp_Compiller/cmake-build-debug/CMakeFiles/decomp_Compiller.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/decomp_Compiller.dir/depend

