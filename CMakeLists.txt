cmake_minimum_required(VERSION 3.21)
project(firstcode C)

set(CMAKE_C_STANDARD 99)

add_executable(firstcode main.c "lab 1.c" "lab 2.cpp" cmake-build-debug/task2.c)
