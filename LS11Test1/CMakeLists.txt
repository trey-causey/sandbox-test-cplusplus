cmake_minimum_required(VERSION 3.17)
project(LS11Test1)

set(CMAKE_CXX_STANDARD 11)

add_executable(LS11Test1 main.cpp src/functions.cpp headers/functions.h src/gearCalc.cpp headers/gearCalc.h)