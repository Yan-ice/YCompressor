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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/yanjiaqin/CLionProjects/YCompress

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/YCompress.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/YCompress.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/YCompress.dir/flags.make

CMakeFiles/YCompress.dir/main.cpp.o: CMakeFiles/YCompress.dir/flags.make
CMakeFiles/YCompress.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/YCompress.dir/main.cpp.o"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/YCompress.dir/main.cpp.o -c /Users/yanjiaqin/CLionProjects/YCompress/main.cpp

CMakeFiles/YCompress.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/YCompress.dir/main.cpp.i"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yanjiaqin/CLionProjects/YCompress/main.cpp > CMakeFiles/YCompress.dir/main.cpp.i

CMakeFiles/YCompress.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/YCompress.dir/main.cpp.s"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yanjiaqin/CLionProjects/YCompress/main.cpp -o CMakeFiles/YCompress.dir/main.cpp.s

CMakeFiles/YCompress.dir/char_buffer.cpp.o: CMakeFiles/YCompress.dir/flags.make
CMakeFiles/YCompress.dir/char_buffer.cpp.o: ../char_buffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/YCompress.dir/char_buffer.cpp.o"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/YCompress.dir/char_buffer.cpp.o -c /Users/yanjiaqin/CLionProjects/YCompress/char_buffer.cpp

CMakeFiles/YCompress.dir/char_buffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/YCompress.dir/char_buffer.cpp.i"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yanjiaqin/CLionProjects/YCompress/char_buffer.cpp > CMakeFiles/YCompress.dir/char_buffer.cpp.i

CMakeFiles/YCompress.dir/char_buffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/YCompress.dir/char_buffer.cpp.s"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yanjiaqin/CLionProjects/YCompress/char_buffer.cpp -o CMakeFiles/YCompress.dir/char_buffer.cpp.s

CMakeFiles/YCompress.dir/yjq_compressor.cpp.o: CMakeFiles/YCompress.dir/flags.make
CMakeFiles/YCompress.dir/yjq_compressor.cpp.o: ../yjq_compressor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/YCompress.dir/yjq_compressor.cpp.o"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/YCompress.dir/yjq_compressor.cpp.o -c /Users/yanjiaqin/CLionProjects/YCompress/yjq_compressor.cpp

CMakeFiles/YCompress.dir/yjq_compressor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/YCompress.dir/yjq_compressor.cpp.i"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/yanjiaqin/CLionProjects/YCompress/yjq_compressor.cpp > CMakeFiles/YCompress.dir/yjq_compressor.cpp.i

CMakeFiles/YCompress.dir/yjq_compressor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/YCompress.dir/yjq_compressor.cpp.s"
	/usr/local/Cellar/gcc@10/10.3.0/bin/g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/yanjiaqin/CLionProjects/YCompress/yjq_compressor.cpp -o CMakeFiles/YCompress.dir/yjq_compressor.cpp.s

# Object files for target YCompress
YCompress_OBJECTS = \
"CMakeFiles/YCompress.dir/main.cpp.o" \
"CMakeFiles/YCompress.dir/char_buffer.cpp.o" \
"CMakeFiles/YCompress.dir/yjq_compressor.cpp.o"

# External object files for target YCompress
YCompress_EXTERNAL_OBJECTS =

YCompress: CMakeFiles/YCompress.dir/main.cpp.o
YCompress: CMakeFiles/YCompress.dir/char_buffer.cpp.o
YCompress: CMakeFiles/YCompress.dir/yjq_compressor.cpp.o
YCompress: CMakeFiles/YCompress.dir/build.make
YCompress: CMakeFiles/YCompress.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable YCompress"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/YCompress.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/YCompress.dir/build: YCompress

.PHONY : CMakeFiles/YCompress.dir/build

CMakeFiles/YCompress.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/YCompress.dir/cmake_clean.cmake
.PHONY : CMakeFiles/YCompress.dir/clean

CMakeFiles/YCompress.dir/depend:
	cd /Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/yanjiaqin/CLionProjects/YCompress /Users/yanjiaqin/CLionProjects/YCompress /Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug /Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug /Users/yanjiaqin/CLionProjects/YCompress/cmake-build-debug/CMakeFiles/YCompress.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/YCompress.dir/depend
