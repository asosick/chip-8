cmake_minimum_required(VERSION 3.21)
project(CHIP_8)

set(CMAKE_CXX_STANDARD 23)

add_executable(CHIP_8 main.cpp src/chip8.h src/types.h src/chip8.cpp)
