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
CMAKE_SOURCE_DIR = C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\LS11Test1.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\LS11Test1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\LS11Test1.dir\flags.make

CMakeFiles\LS11Test1.dir\main.cpp.obj: CMakeFiles\LS11Test1.dir\flags.make
CMakeFiles\LS11Test1.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LS11Test1.dir/main.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\LS11Test1.dir\main.cpp.obj /FdCMakeFiles\LS11Test1.dir\ /FS -c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\main.cpp
<<

CMakeFiles\LS11Test1.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LS11Test1.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\LS11Test1.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\main.cpp
<<

CMakeFiles\LS11Test1.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LS11Test1.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\LS11Test1.dir\main.cpp.s /c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\main.cpp
<<

CMakeFiles\LS11Test1.dir\src\functions.cpp.obj: CMakeFiles\LS11Test1.dir\flags.make
CMakeFiles\LS11Test1.dir\src\functions.cpp.obj: ..\src\functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LS11Test1.dir/src/functions.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\LS11Test1.dir\src\functions.cpp.obj /FdCMakeFiles\LS11Test1.dir\ /FS -c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\src\functions.cpp
<<

CMakeFiles\LS11Test1.dir\src\functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LS11Test1.dir/src/functions.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\LS11Test1.dir\src\functions.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\src\functions.cpp
<<

CMakeFiles\LS11Test1.dir\src\functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LS11Test1.dir/src/functions.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\LS11Test1.dir\src\functions.cpp.s /c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\src\functions.cpp
<<

CMakeFiles\LS11Test1.dir\src\gearCalc.cpp.obj: CMakeFiles\LS11Test1.dir\flags.make
CMakeFiles\LS11Test1.dir\src\gearCalc.cpp.obj: ..\src\gearCalc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LS11Test1.dir/src/gearCalc.cpp.obj"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\LS11Test1.dir\src\gearCalc.cpp.obj /FdCMakeFiles\LS11Test1.dir\ /FS -c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\src\gearCalc.cpp
<<

CMakeFiles\LS11Test1.dir\src\gearCalc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LS11Test1.dir/src/gearCalc.cpp.i"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe > CMakeFiles\LS11Test1.dir\src\gearCalc.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\src\gearCalc.cpp
<<

CMakeFiles\LS11Test1.dir\src\gearCalc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LS11Test1.dir/src/gearCalc.cpp.s"
	C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\LS11Test1.dir\src\gearCalc.cpp.s /c C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\src\gearCalc.cpp
<<

# Object files for target LS11Test1
LS11Test1_OBJECTS = \
"CMakeFiles\LS11Test1.dir\main.cpp.obj" \
"CMakeFiles\LS11Test1.dir\src\functions.cpp.obj" \
"CMakeFiles\LS11Test1.dir\src\gearCalc.cpp.obj"

# External object files for target LS11Test1
LS11Test1_EXTERNAL_OBJECTS =

LS11Test1.exe: CMakeFiles\LS11Test1.dir\main.cpp.obj
LS11Test1.exe: CMakeFiles\LS11Test1.dir\src\functions.cpp.obj
LS11Test1.exe: CMakeFiles\LS11Test1.dir\src\gearCalc.cpp.obj
LS11Test1.exe: CMakeFiles\LS11Test1.dir\build.make
LS11Test1.exe: CMakeFiles\LS11Test1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable LS11Test1.exe"
	"C:\Program Files\JetBrains\CLion 2020.2.1\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\LS11Test1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100183~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~4\2019\COMMUN~1\VC\Tools\MSVC\1427~1.291\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\LS11Test1.dir\objects1.rsp @<<
 /out:LS11Test1.exe /implib:LS11Test1.lib /pdb:C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug\LS11Test1.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\LS11Test1.dir\build: LS11Test1.exe

.PHONY : CMakeFiles\LS11Test1.dir\build

CMakeFiles\LS11Test1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LS11Test1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\LS11Test1.dir\clean

CMakeFiles\LS11Test1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1 C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1 C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug C:\My\Repos\tests\sandboxes\sandbox-test-cplusplus\LS11Test1\cmake-build-debug\CMakeFiles\LS11Test1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\LS11Test1.dir\depend

