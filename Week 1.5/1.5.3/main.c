#include <stdio.h>
#include "functions.h"

int main() {
    // Array aanmaken met 10 random getallen tussen 1 en 10
    int numbers[10] = {
            random_int(1, 10),
            random_int(1, 10),
            random_int(1, 10),
            random_int(1, 10),
            random_int(1, 10),
            random_int(1, 10),
            random_int(1, 10),
            random_int(1, 10),
            random_int(1, 10),
            random_int(1, 10),
    };

    int number_amount = 9;

    printf("Contents: ");
    // Array uitprinten + komma's
    for (int i = 0; i <= number_amount; ++i) {
        printf("%2d", numbers[i]);
        if(i != 9){
            printf(", ");
        }
    }

    // User om input vragen, getal tussen 1-10.
    int user_number = 0;
    while (user_number <= 0 || user_number > 10){
        user_number = read_int("\nEnter a number (1-10):");
        if(user_number <= 0 || user_number > 10){
            printf("That's not a valid input");
        }
    }

    int counter = 0;

    for (int i = 0; i < 10; ++i) {
        // Checken of de input gelijk is aan het getal. Zo ja: volgende getallen 1 plekje naar voren schuiven.

        if (numbers[i] == user_number){
            counter++;
            number_amount = number_amount - 1;

        } else{
            numbers[i-counter] = numbers[i];
        }

    }

    // Nieuwe array uitprinten +
    for (int i = 0; i <= number_amount; ++i) {
        printf("%2d", numbers[i]);
        if(i != number_amount){
            printf(", ");
        }
    }

    return 0;
}
