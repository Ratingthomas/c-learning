//
// Created by Thomas Levels on 15/01/2024.
//

#ifndef MASTERMIND_GUES_H
#define MASTERMIND_GUES_H

#include "score.h"

typedef struct {
    char guess[SECRET_SIZE];
    score_t score;
} scored_guess_t; // A guess and its score

#endif //MASTERMIND_GUES_H
