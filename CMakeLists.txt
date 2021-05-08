cmake_minimum_required(VERSION 3.19)
project(dcc C)

set(CMAKE_C_STANDARD 99)

add_executable(dcc main.c pre_reader.h compiler.c compiler.h header.h pre_reader.c num_conv.h num_conv.c)

target_link_libraries(dcc -lm)