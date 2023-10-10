cmake_minimum_required(VERSION 3.26)
project(1_5_1 C)

set(CMAKE_C_STANDARD 11)

add_executable(1_5_1 main.c
        functions.h
        functions.c)

#target_compile_options(1_5_1 PRIVATE -Wall -Wextra -pedantic -Werror)
