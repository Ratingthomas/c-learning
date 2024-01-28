cmake_minimum_required(VERSION 3.27)
project(mastermind C)

set(CMAKE_C_STANDARD 11)

add_executable(mastermind main.c functions.c
        config.h
        gues.h
        score.h
        game.h
        board.h
        game.c
)

target_compile_options(mastermind PRIVATE -Wall -Wextra -pedantic -Werror)