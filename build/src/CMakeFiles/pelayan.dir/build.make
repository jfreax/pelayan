# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canoncical targets will work.
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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jens/C++/pelayan

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jens/C++/pelayan/build

# Include any dependencies generated for this target.
include src/CMakeFiles/pelayan.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/pelayan.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/pelayan.dir/flags.make

src/CMakeFiles/pelayan.dir/main.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/main.c.o: ../src/main.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/main.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/main.c.o   -c /home/jens/C++/pelayan/src/main.c

src/CMakeFiles/pelayan.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/main.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/main.c > CMakeFiles/pelayan.dir/main.c.i

src/CMakeFiles/pelayan.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/main.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/main.c -o CMakeFiles/pelayan.dir/main.c.s

src/CMakeFiles/pelayan.dir/main.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/main.c.o.requires

src/CMakeFiles/pelayan.dir/main.c.o.provides: src/CMakeFiles/pelayan.dir/main.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/main.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/main.c.o.provides

src/CMakeFiles/pelayan.dir/main.c.o.provides.build: src/CMakeFiles/pelayan.dir/main.c.o
.PHONY : src/CMakeFiles/pelayan.dir/main.c.o.provides.build

src/CMakeFiles/pelayan.dir/filetype.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/filetype.c.o: ../src/filetype.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/filetype.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/filetype.c.o   -c /home/jens/C++/pelayan/src/filetype.c

src/CMakeFiles/pelayan.dir/filetype.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/filetype.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/filetype.c > CMakeFiles/pelayan.dir/filetype.c.i

src/CMakeFiles/pelayan.dir/filetype.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/filetype.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/filetype.c -o CMakeFiles/pelayan.dir/filetype.c.s

src/CMakeFiles/pelayan.dir/filetype.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/filetype.c.o.requires

src/CMakeFiles/pelayan.dir/filetype.c.o.provides: src/CMakeFiles/pelayan.dir/filetype.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/filetype.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/filetype.c.o.provides

src/CMakeFiles/pelayan.dir/filetype.c.o.provides.build: src/CMakeFiles/pelayan.dir/filetype.c.o
.PHONY : src/CMakeFiles/pelayan.dir/filetype.c.o.provides.build

src/CMakeFiles/pelayan.dir/intern/help.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/intern/help.c.o: ../src/intern/help.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/intern/help.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/intern/help.c.o   -c /home/jens/C++/pelayan/src/intern/help.c

src/CMakeFiles/pelayan.dir/intern/help.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/intern/help.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/intern/help.c > CMakeFiles/pelayan.dir/intern/help.c.i

src/CMakeFiles/pelayan.dir/intern/help.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/intern/help.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/intern/help.c -o CMakeFiles/pelayan.dir/intern/help.c.s

src/CMakeFiles/pelayan.dir/intern/help.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/intern/help.c.o.requires

src/CMakeFiles/pelayan.dir/intern/help.c.o.provides: src/CMakeFiles/pelayan.dir/intern/help.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/intern/help.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/intern/help.c.o.provides

src/CMakeFiles/pelayan.dir/intern/help.c.o.provides.build: src/CMakeFiles/pelayan.dir/intern/help.c.o
.PHONY : src/CMakeFiles/pelayan.dir/intern/help.c.o.provides.build

src/CMakeFiles/pelayan.dir/intern/settings.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/intern/settings.c.o: ../src/intern/settings.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/intern/settings.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/intern/settings.c.o   -c /home/jens/C++/pelayan/src/intern/settings.c

src/CMakeFiles/pelayan.dir/intern/settings.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/intern/settings.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/intern/settings.c > CMakeFiles/pelayan.dir/intern/settings.c.i

src/CMakeFiles/pelayan.dir/intern/settings.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/intern/settings.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/intern/settings.c -o CMakeFiles/pelayan.dir/intern/settings.c.s

src/CMakeFiles/pelayan.dir/intern/settings.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/intern/settings.c.o.requires

src/CMakeFiles/pelayan.dir/intern/settings.c.o.provides: src/CMakeFiles/pelayan.dir/intern/settings.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/intern/settings.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/intern/settings.c.o.provides

src/CMakeFiles/pelayan.dir/intern/settings.c.o.provides.build: src/CMakeFiles/pelayan.dir/intern/settings.c.o
.PHONY : src/CMakeFiles/pelayan.dir/intern/settings.c.o.provides.build

src/CMakeFiles/pelayan.dir/intern/gzip.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/intern/gzip.c.o: ../src/intern/gzip.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/intern/gzip.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/intern/gzip.c.o   -c /home/jens/C++/pelayan/src/intern/gzip.c

src/CMakeFiles/pelayan.dir/intern/gzip.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/intern/gzip.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/intern/gzip.c > CMakeFiles/pelayan.dir/intern/gzip.c.i

src/CMakeFiles/pelayan.dir/intern/gzip.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/intern/gzip.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/intern/gzip.c -o CMakeFiles/pelayan.dir/intern/gzip.c.s

src/CMakeFiles/pelayan.dir/intern/gzip.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/intern/gzip.c.o.requires

src/CMakeFiles/pelayan.dir/intern/gzip.c.o.provides: src/CMakeFiles/pelayan.dir/intern/gzip.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/intern/gzip.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/intern/gzip.c.o.provides

src/CMakeFiles/pelayan.dir/intern/gzip.c.o.provides.build: src/CMakeFiles/pelayan.dir/intern/gzip.c.o
.PHONY : src/CMakeFiles/pelayan.dir/intern/gzip.c.o.provides.build

src/CMakeFiles/pelayan.dir/socket/server.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/socket/server.c.o: ../src/socket/server.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/socket/server.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/socket/server.c.o   -c /home/jens/C++/pelayan/src/socket/server.c

src/CMakeFiles/pelayan.dir/socket/server.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/socket/server.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/socket/server.c > CMakeFiles/pelayan.dir/socket/server.c.i

src/CMakeFiles/pelayan.dir/socket/server.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/socket/server.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/socket/server.c -o CMakeFiles/pelayan.dir/socket/server.c.s

src/CMakeFiles/pelayan.dir/socket/server.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/socket/server.c.o.requires

src/CMakeFiles/pelayan.dir/socket/server.c.o.provides: src/CMakeFiles/pelayan.dir/socket/server.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/socket/server.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/socket/server.c.o.provides

src/CMakeFiles/pelayan.dir/socket/server.c.o.provides.build: src/CMakeFiles/pelayan.dir/socket/server.c.o
.PHONY : src/CMakeFiles/pelayan.dir/socket/server.c.o.provides.build

src/CMakeFiles/pelayan.dir/socket/client.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/socket/client.c.o: ../src/socket/client.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/socket/client.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/socket/client.c.o   -c /home/jens/C++/pelayan/src/socket/client.c

src/CMakeFiles/pelayan.dir/socket/client.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/socket/client.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/socket/client.c > CMakeFiles/pelayan.dir/socket/client.c.i

src/CMakeFiles/pelayan.dir/socket/client.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/socket/client.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/socket/client.c -o CMakeFiles/pelayan.dir/socket/client.c.s

src/CMakeFiles/pelayan.dir/socket/client.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/socket/client.c.o.requires

src/CMakeFiles/pelayan.dir/socket/client.c.o.provides: src/CMakeFiles/pelayan.dir/socket/client.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/socket/client.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/socket/client.c.o.provides

src/CMakeFiles/pelayan.dir/socket/client.c.o.provides.build: src/CMakeFiles/pelayan.dir/socket/client.c.o
.PHONY : src/CMakeFiles/pelayan.dir/socket/client.c.o.provides.build

src/CMakeFiles/pelayan.dir/socket/send.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/socket/send.c.o: ../src/socket/send.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/socket/send.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/socket/send.c.o   -c /home/jens/C++/pelayan/src/socket/send.c

src/CMakeFiles/pelayan.dir/socket/send.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/socket/send.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/socket/send.c > CMakeFiles/pelayan.dir/socket/send.c.i

src/CMakeFiles/pelayan.dir/socket/send.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/socket/send.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/socket/send.c -o CMakeFiles/pelayan.dir/socket/send.c.s

src/CMakeFiles/pelayan.dir/socket/send.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/socket/send.c.o.requires

src/CMakeFiles/pelayan.dir/socket/send.c.o.provides: src/CMakeFiles/pelayan.dir/socket/send.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/socket/send.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/socket/send.c.o.provides

src/CMakeFiles/pelayan.dir/socket/send.c.o.provides.build: src/CMakeFiles/pelayan.dir/socket/send.c.o
.PHONY : src/CMakeFiles/pelayan.dir/socket/send.c.o.provides.build

src/CMakeFiles/pelayan.dir/http/buffer.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/http/buffer.c.o: ../src/http/buffer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/http/buffer.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/http/buffer.c.o   -c /home/jens/C++/pelayan/src/http/buffer.c

src/CMakeFiles/pelayan.dir/http/buffer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/http/buffer.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/http/buffer.c > CMakeFiles/pelayan.dir/http/buffer.c.i

src/CMakeFiles/pelayan.dir/http/buffer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/http/buffer.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/http/buffer.c -o CMakeFiles/pelayan.dir/http/buffer.c.s

src/CMakeFiles/pelayan.dir/http/buffer.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/http/buffer.c.o.requires

src/CMakeFiles/pelayan.dir/http/buffer.c.o.provides: src/CMakeFiles/pelayan.dir/http/buffer.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/http/buffer.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/http/buffer.c.o.provides

src/CMakeFiles/pelayan.dir/http/buffer.c.o.provides.build: src/CMakeFiles/pelayan.dir/http/buffer.c.o
.PHONY : src/CMakeFiles/pelayan.dir/http/buffer.c.o.provides.build

src/CMakeFiles/pelayan.dir/http/request.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/http/request.c.o: ../src/http/request.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/http/request.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/http/request.c.o   -c /home/jens/C++/pelayan/src/http/request.c

src/CMakeFiles/pelayan.dir/http/request.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/http/request.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/http/request.c > CMakeFiles/pelayan.dir/http/request.c.i

src/CMakeFiles/pelayan.dir/http/request.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/http/request.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/http/request.c -o CMakeFiles/pelayan.dir/http/request.c.s

src/CMakeFiles/pelayan.dir/http/request.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/http/request.c.o.requires

src/CMakeFiles/pelayan.dir/http/request.c.o.provides: src/CMakeFiles/pelayan.dir/http/request.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/http/request.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/http/request.c.o.provides

src/CMakeFiles/pelayan.dir/http/request.c.o.provides.build: src/CMakeFiles/pelayan.dir/http/request.c.o
.PHONY : src/CMakeFiles/pelayan.dir/http/request.c.o.provides.build

src/CMakeFiles/pelayan.dir/http/response.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/http/response.c.o: ../src/http/response.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/http/response.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/http/response.c.o   -c /home/jens/C++/pelayan/src/http/response.c

src/CMakeFiles/pelayan.dir/http/response.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/http/response.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/http/response.c > CMakeFiles/pelayan.dir/http/response.c.i

src/CMakeFiles/pelayan.dir/http/response.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/http/response.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/http/response.c -o CMakeFiles/pelayan.dir/http/response.c.s

src/CMakeFiles/pelayan.dir/http/response.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/http/response.c.o.requires

src/CMakeFiles/pelayan.dir/http/response.c.o.provides: src/CMakeFiles/pelayan.dir/http/response.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/http/response.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/http/response.c.o.provides

src/CMakeFiles/pelayan.dir/http/response.c.o.provides.build: src/CMakeFiles/pelayan.dir/http/response.c.o
.PHONY : src/CMakeFiles/pelayan.dir/http/response.c.o.provides.build

src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o: ../src/misc/tokenizer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/misc/tokenizer.c.o   -c /home/jens/C++/pelayan/src/misc/tokenizer.c

src/CMakeFiles/pelayan.dir/misc/tokenizer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/misc/tokenizer.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/misc/tokenizer.c > CMakeFiles/pelayan.dir/misc/tokenizer.c.i

src/CMakeFiles/pelayan.dir/misc/tokenizer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/misc/tokenizer.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/misc/tokenizer.c -o CMakeFiles/pelayan.dir/misc/tokenizer.c.s

src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.requires

src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.provides: src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.provides

src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.provides.build: src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o
.PHONY : src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.provides.build

src/CMakeFiles/pelayan.dir/misc/mstring.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/misc/mstring.c.o: ../src/misc/mstring.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/misc/mstring.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/misc/mstring.c.o   -c /home/jens/C++/pelayan/src/misc/mstring.c

src/CMakeFiles/pelayan.dir/misc/mstring.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/misc/mstring.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/misc/mstring.c > CMakeFiles/pelayan.dir/misc/mstring.c.i

src/CMakeFiles/pelayan.dir/misc/mstring.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/misc/mstring.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/misc/mstring.c -o CMakeFiles/pelayan.dir/misc/mstring.c.s

src/CMakeFiles/pelayan.dir/misc/mstring.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/misc/mstring.c.o.requires

src/CMakeFiles/pelayan.dir/misc/mstring.c.o.provides: src/CMakeFiles/pelayan.dir/misc/mstring.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/misc/mstring.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/misc/mstring.c.o.provides

src/CMakeFiles/pelayan.dir/misc/mstring.c.o.provides.build: src/CMakeFiles/pelayan.dir/misc/mstring.c.o
.PHONY : src/CMakeFiles/pelayan.dir/misc/mstring.c.o.provides.build

src/CMakeFiles/pelayan.dir/misc/dstring.c.o: src/CMakeFiles/pelayan.dir/flags.make
src/CMakeFiles/pelayan.dir/misc/dstring.c.o: ../src/misc/dstring.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jens/C++/pelayan/build/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object src/CMakeFiles/pelayan.dir/misc/dstring.c.o"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/pelayan.dir/misc/dstring.c.o   -c /home/jens/C++/pelayan/src/misc/dstring.c

src/CMakeFiles/pelayan.dir/misc/dstring.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pelayan.dir/misc/dstring.c.i"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -E /home/jens/C++/pelayan/src/misc/dstring.c > CMakeFiles/pelayan.dir/misc/dstring.c.i

src/CMakeFiles/pelayan.dir/misc/dstring.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pelayan.dir/misc/dstring.c.s"
	cd /home/jens/C++/pelayan/build/src && /usr/bin/gcc  $(C_DEFINES) $(C_FLAGS) -S /home/jens/C++/pelayan/src/misc/dstring.c -o CMakeFiles/pelayan.dir/misc/dstring.c.s

src/CMakeFiles/pelayan.dir/misc/dstring.c.o.requires:
.PHONY : src/CMakeFiles/pelayan.dir/misc/dstring.c.o.requires

src/CMakeFiles/pelayan.dir/misc/dstring.c.o.provides: src/CMakeFiles/pelayan.dir/misc/dstring.c.o.requires
	$(MAKE) -f src/CMakeFiles/pelayan.dir/build.make src/CMakeFiles/pelayan.dir/misc/dstring.c.o.provides.build
.PHONY : src/CMakeFiles/pelayan.dir/misc/dstring.c.o.provides

src/CMakeFiles/pelayan.dir/misc/dstring.c.o.provides.build: src/CMakeFiles/pelayan.dir/misc/dstring.c.o
.PHONY : src/CMakeFiles/pelayan.dir/misc/dstring.c.o.provides.build

# Object files for target pelayan
pelayan_OBJECTS = \
"CMakeFiles/pelayan.dir/main.c.o" \
"CMakeFiles/pelayan.dir/filetype.c.o" \
"CMakeFiles/pelayan.dir/intern/help.c.o" \
"CMakeFiles/pelayan.dir/intern/settings.c.o" \
"CMakeFiles/pelayan.dir/intern/gzip.c.o" \
"CMakeFiles/pelayan.dir/socket/server.c.o" \
"CMakeFiles/pelayan.dir/socket/client.c.o" \
"CMakeFiles/pelayan.dir/socket/send.c.o" \
"CMakeFiles/pelayan.dir/http/buffer.c.o" \
"CMakeFiles/pelayan.dir/http/request.c.o" \
"CMakeFiles/pelayan.dir/http/response.c.o" \
"CMakeFiles/pelayan.dir/misc/tokenizer.c.o" \
"CMakeFiles/pelayan.dir/misc/mstring.c.o" \
"CMakeFiles/pelayan.dir/misc/dstring.c.o"

# External object files for target pelayan
pelayan_EXTERNAL_OBJECTS =

src/pelayan: src/CMakeFiles/pelayan.dir/main.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/filetype.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/intern/help.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/intern/settings.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/intern/gzip.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/socket/server.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/socket/client.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/socket/send.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/http/buffer.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/http/request.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/http/response.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/misc/mstring.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/misc/dstring.c.o
src/pelayan: src/CMakeFiles/pelayan.dir/build.make
src/pelayan: src/CMakeFiles/pelayan.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable pelayan"
	cd /home/jens/C++/pelayan/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pelayan.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/pelayan.dir/build: src/pelayan
.PHONY : src/CMakeFiles/pelayan.dir/build

src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/main.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/filetype.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/intern/help.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/intern/settings.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/intern/gzip.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/socket/server.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/socket/client.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/socket/send.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/http/buffer.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/http/request.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/http/response.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/misc/tokenizer.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/misc/mstring.c.o.requires
src/CMakeFiles/pelayan.dir/requires: src/CMakeFiles/pelayan.dir/misc/dstring.c.o.requires
.PHONY : src/CMakeFiles/pelayan.dir/requires

src/CMakeFiles/pelayan.dir/clean:
	cd /home/jens/C++/pelayan/build/src && $(CMAKE_COMMAND) -P CMakeFiles/pelayan.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/pelayan.dir/clean

src/CMakeFiles/pelayan.dir/depend:
	cd /home/jens/C++/pelayan/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jens/C++/pelayan /home/jens/C++/pelayan/src /home/jens/C++/pelayan/build /home/jens/C++/pelayan/build/src /home/jens/C++/pelayan/build/src/CMakeFiles/pelayan.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/pelayan.dir/depend

