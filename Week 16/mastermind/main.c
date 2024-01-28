#include <stdio.h>
#include <string.h>
#include "functions.h"
#include "config.h"
#include "gues.h"
#include "score.h"
#include "game.h"
#include "board.h"

int main(void) {
    // generate a secret code & initialize the board
    game_t game;
    for (int i = 0; i < SECRET_SIZE; i++) {
        game.secret[i] = 'A' + random_int(0, NUM_OPTIONS - 1);
    }
    game.board.num_guesses = 0;

    char guess[SECRET_SIZE + 1];

    display_welcome_message();



    // while the game is not over
    while ((game.board.num_guesses < MAX_GUESSES) && (game.board.num_guesses == 0 ||
                                                      game.board.guesses[game.board.num_guesses -
                                                                         1].score.correct_and_in_place < SECRET_SIZE)) {
        // print the board
        if (game.board.num_guesses != 0) {
            printf("\n\nguess | ");
            for (int i = 0; i < SECRET_SIZE; i++) printf("  ");
            printf("|  C: # correct, M: # misplaced\n");
            for (int i = 0; i < game.board.num_guesses; i++) {
                printf("%4d  | ", i + 1);
                for (int j = 0; j < SECRET_SIZE; j++) {
                    printf("%c ", game.board.guesses[i].guess[j]);
                }
                printf("|  C: %d, M: %d\n", game.board.guesses[i].score.correct_and_in_place,
                       game.board.guesses[i].score.correct_but_misplaced);
            }
            printf("\n");
        }

        // print nr. of moves remaining if this was not the first move
        if (game.board.num_guesses != 0) {
            printf("You have %d guesses remaining.\n", MAX_GUESSES - game.board.num_guesses);
        }

        // get a guess from the user
        bool valid_guess;
        const char *input;
        do {
            if (game.board.num_guesses == 0) printf("Enter your first guess: ");
            else printf("Enter your guess: ");
            input = read_string("");
            valid_guess = true;
            if (strlen(input) != SECRET_SIZE) valid_guess = false;
            else {
                for (int i = 0; i < SECRET_SIZE; i++) {
                    if (input[i] < 'A' || input[i] > 'A' + NUM_OPTIONS - 1) {
                        valid_guess = false;
                        break;
                    }
                }
            }
            if (!valid_guess) printf("Invalid guess! ");
        }
        while (!valid_guess);
        strcpy(guess, input);

        // score the guess
        score_t score = {0, 0};
        int counts[NUM_OPTIONS] = {0};
        for (int i = 0; i < SECRET_SIZE; i++) counts[game.secret[i] - 'A']++;
        score.correct_and_in_place = 0;
        score.correct_but_misplaced = 0;
        for (int i = 0; i < SECRET_SIZE; i++) {
            if (guess[i] == game.secret[i]) {
                score.correct_and_in_place++;
                counts[game.secret[i] - 'A']--;
            }
        }
        for (int i = 0; i < SECRET_SIZE; i++) {
            if (guess[i] != game.secret[i] && counts[guess[i] - 'A'] > 0) {
                score.correct_but_misplaced++;
                counts[guess[i] - 'A']--;
            }
        }

        scored_guess_t scored = {.score = score};
        strncpy(scored.guess, guess, SECRET_SIZE);

        // add the guess to the board
        game.board.guesses[game.board.num_guesses] = scored;
        game.board.num_guesses++;
    }

    // if the game was won, print a win message
    if (game.board.num_guesses > 0 &&
        game.board.guesses[game.board.num_guesses - 1].score.correct_and_in_place == SECRET_SIZE) {
        printf("That was the secret code!\nYou won in %d guesses!\n", game.board.num_guesses);
    } else {
        printf("You lost!\nThe secret code was: %s\n", game.secret);
    }

    read_string("Press enter to exit...");
    return 0;
}

