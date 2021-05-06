cmake_minimum_required(VERSION 3.19)
project(decomp_Compiller C)

set(CMAKE_C_STANDARD 99)

add_executable(decomp_Compiller main.c pre_reader.h compiler.c compiler.h header.h pre_reader.c)