#include <stdio.h>
#include "functions.h"

int main() {
    random_int(1, 100);
    int random_num = random_int(1, 100);
    printf("I'm thinking of a number between 1 and 100...");
    printf("\n");

    int num_gues = 0;
    int guesses = 0;

    while (num_gues != 1){
        int usernum = read_int("Guess the number: ");
        guesses++;

        if(usernum < random_num){
            printf("To low!");
            printf("\n");
        }
        else if(usernum > random_num){
            printf("To high!");
            printf("\n");
        }
        else if(usernum == random_num){
            printf("Correct! You needed ");
            printf("%d", guesses);
            printf("\n");
            num_gues = 1;
        }
    }

    return 0;
}
