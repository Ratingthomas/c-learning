//
// Created by Thomas Levels on 15/01/2024.
//

#ifndef MASTERMIND_SCORE_H
#define MASTERMIND_SCORE_H

typedef struct {
    int correct_and_in_place;   // Correct character in the correct position
    int correct_but_misplaced;  // Correct character in the wrong position
} score_t; // A score for a guess

#endif //MASTERMIND_SCORE_H
