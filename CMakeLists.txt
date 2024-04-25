cmake_minimum_required(VERSION 3.26)
project(cyclic_mode CXX)

set(CMAKE_CXX_STANDARD 11)

add_executable(cyclic_mode
        src/coder.cpp
        src/poly_math.cpp
        src/main.cpp
        src/decoder.h
        src/decoder.cpp
)
