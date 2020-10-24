cmake_minimum_required(VERSION 3.17)
project(LS14Test2)

set(CMAKE_CXX_STANDARD 14)

add_executable(LS14Test2 main.cpp src/ClockType.cpp header/ClockType.h src/test.cpp header/test.h src/Solution.cpp header/Solution.h)