cmake_minimum_required(VERSION 3.17)
project(LS14Test1)

set(CMAKE_CXX_STANDARD 14)

add_executable(LS14Test1 main.cpp src/Account.cpp header/Account.h header/Transaction.h src/Transaction.cpp)