cmake_minimum_required(VERSION 3.26)
project(cyclic_mode C)

set(CMAKE_C_STANDARD 11)

add_executable(cyclic_mode
        src/coder.c
        src/poly_math.c
        src/main.c
        src/decoder.h
        src/decoder.c
)
