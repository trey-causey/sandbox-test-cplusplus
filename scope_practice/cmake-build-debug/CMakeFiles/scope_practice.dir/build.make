# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\scope_practice.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\scope_practice.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\scope_practice.dir\flags.make

CMakeFiles\scope_practice.dir\main.cpp.obj: CMakeFiles\scope_practice.dir\flags.make
CMakeFiles\scope_practice.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/scope_practice.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\scope_practice.dir\main.cpp.obj /FdCMakeFiles\scope_practice.dir\ /FS -c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\main.cpp
<<

CMakeFiles\scope_practice.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scope_practice.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\scope_practice.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\main.cpp
<<

CMakeFiles\scope_practice.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scope_practice.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\scope_practice.dir\main.cpp.s /c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\main.cpp
<<

CMakeFiles\scope_practice.dir\src\Scope.cpp.obj: CMakeFiles\scope_practice.dir\flags.make
CMakeFiles\scope_practice.dir\src\Scope.cpp.obj: ..\src\Scope.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/scope_practice.dir/src/Scope.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\scope_practice.dir\src\Scope.cpp.obj /FdCMakeFiles\scope_practice.dir\ /FS -c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\src\Scope.cpp
<<

CMakeFiles\scope_practice.dir\src\Scope.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/scope_practice.dir/src/Scope.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\scope_practice.dir\src\Scope.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\src\Scope.cpp
<<

CMakeFiles\scope_practice.dir\src\Scope.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/scope_practice.dir/src/Scope.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\scope_practice.dir\src\Scope.cpp.s /c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\src\Scope.cpp
<<

# Object files for target scope_practice
scope_practice_OBJECTS = \
"CMakeFiles\scope_practice.dir\main.cpp.obj" \
"CMakeFiles\scope_practice.dir\src\Scope.cpp.obj"

# External object files for target scope_practice
scope_practice_EXTERNAL_OBJECTS =

scope_practice.exe: CMakeFiles\scope_practice.dir\main.cpp.obj
scope_practice.exe: CMakeFiles\scope_practice.dir\src\Scope.cpp.obj
scope_practice.exe: CMakeFiles\scope_practice.dir\build.make
scope_practice.exe: CMakeFiles\scope_practice.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable scope_practice.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\scope_practice.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\scope_practice.dir\objects1.rsp @<<
 /out:scope_practice.exe /implib:scope_practice.lib /pdb:C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\cmake-build-debug\scope_practice.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\scope_practice.dir\build: scope_practice.exe

.PHONY : CMakeFiles\scope_practice.dir\build

CMakeFiles\scope_practice.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\scope_practice.dir\cmake_clean.cmake
.PHONY : CMakeFiles\scope_practice.dir\clean

CMakeFiles\scope_practice.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\cmake-build-debug C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\cmake-build-debug C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\scope_practice\cmake-build-debug\CMakeFiles\scope_practice.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\scope_practice.dir\depend

