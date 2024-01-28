//
// Created by Thomas Levels on 15/01/2024.
//

#include "board.h"

#ifndef MASTERMIND_GAME_H
#define MASTERMIND_GAME_H

typedef struct {
    char secret[SECRET_SIZE];
    board_t board;
} game_t; // The mastermind game

/// Reads an integer from the user.
/// @param prompt The prompt to display to the user.
/// @return The integer entered by the user.
void display_welcome_message();

#endif //MASTERMIND_GAME_H
