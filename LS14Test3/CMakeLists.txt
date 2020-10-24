cmake_minimum_required(VERSION 3.17)
project(LS14Test3)

set(CMAKE_CXX_STANDARD 14)

add_executable(LS14Test3 main.cpp src/grade_school.cpp header/grade_school.h header/Collections.h src/Collections.cpp src/SimpleClasses.cpp header/SimpleClasses.h)