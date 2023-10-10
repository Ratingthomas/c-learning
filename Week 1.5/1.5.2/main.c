#include <stdio.h>
#include "functions.h"

int main() {
    // 10 random getalen tussen en 1 en 10 genereren en meteen in een array zetten.
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

    printf("Contents: ");
    // Array printen
    for (int i = 0; i < 10; ++i) {
        printf("%d", numbers[i]);
        if(i != 9){
            printf(", ");
        }
    }

    // Gebruiker input array aanmaken.
    int user_numbers[3] = {0, 0, 0};

    // 3 keer de gebruiker vragen om input en de input in de array gooien.
    user_numbers[0] = read_int("\nEnter a number: ");
    user_numbers[1] = read_int("Enter a number: ");
    user_numbers[2] = read_int("Enter a number: ");

    int gues = 0;

    for (int i = 0; i < 10; ++i) {
        // Door alle getalen in de array gaan. Dan kijken of het getal in array gelijk is aan het eerste getal dat de gebruiker
        // heeft ingevuld. Als dit zo is checken of het tweede getal gelijk is aan de tweede input. Als die ook gelijk zijn
        // checken of de derde input ook gelijk is.
        if(numbers[i] == user_numbers[0] && numbers[i+1] == user_numbers[1] && numbers[i+2] == user_numbers[2]){
            // Array uitprinten + mogelijke index van de array.
            printf("The array {%d, %d, %d} is contained in the larger array", user_numbers[0], user_numbers[1], user_numbers[2]);
            printf(", starting at index %d.", i);
            gues = 1;
        }
    }

    // Array zat in de grote array dus een andere tekst uitprinten.
    if(gues == 0) {
        printf("The array {%d, %d, %d} is not contained in the larger array.", user_numbers[0], user_numbers[1], user_numbers[2]);
    }

    return 0;
}
