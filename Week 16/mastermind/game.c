//
// Created by Thomas Levels on 15/01/2024.
//
#include "game.h"

void display_welcome_message(){
    // print the instructions for the game
    printf("Welcome to Mastermind!\n");
    printf("The computer has generated a secret code\n");
    printf("This code consists of %d characters in the range 'A'..'%c'.\n", SECRET_SIZE, 'A' + NUM_OPTIONS - 1);
    printf("Your goal is to guess the code in as few guesses as possible.\n");
    printf("After each guess, you will be told:\n");
    printf("  -  How many characters are correct and in the correct position.\n");
    printf("  -  How many characters are correct but in the wrong position.\n");
    printf("The game ends when you guess the code or run out of guesses (you have %d guesses).\n", MAX_GUESSES);
    printf("Good luck!\n\n");
    printf("A valid guess is %d characters in range 'A'..'%c', such as \"", SECRET_SIZE, 'A' + NUM_OPTIONS - 1);
    for (int i = 0; i < SECRET_SIZE; i++) printf("A");
    printf("\"\n\n");
}