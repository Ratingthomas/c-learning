//
// Created by Thomas Levels on 15/01/2024.
//

#ifndef MASTERMIND_BOARD_H
#define MASTERMIND_BOARD_H

typedef struct {
    scored_guess_t guesses[MAX_GUESSES];
    int num_guesses;
} board_t; // The mastermind board

#endif //MASTERMIND_BOARD_H
