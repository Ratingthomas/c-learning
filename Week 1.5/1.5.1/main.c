#include <stdio.h>
#include "functions.h"

int main() {
    // Eerst 10 random getalen genereren tussen de -10 en 10 daarna deze 10 nummers in de array gooien.
    float numbers[10] = {
            random_float(-10, 10),
            random_float(-10, 10),
            random_float(-10, 10),
            random_float(-10, 10),
            random_float(-10, 10),
            random_float(-10, 10),
            random_float(-10, 10),
            random_float(-10, 10),
            random_float(-10, 10),
            random_float(-10, 10),
    };

    printf("Before:");

    float gemiddelde = 0;

    // Array uitprinten + alle getalen bij elkaar optellen.
    for (int i = 0; i < 10; ++i) {
        printf("%5.1f", numbers[i]);
        if (i != 9) {
            printf(",");
        }
        gemiddelde = gemiddelde + numbers[i];
    }

    // Gemiddelde berekenen door alle 10 getalen te delen door 10
    gemiddelde = gemiddelde / 10;

    printf("\n Mean: %5.1f", gemiddelde);

    // Dan de array weer uitprinten maar alle resulaten min het gemiddelde
    printf("\n After:");
    for (int i = 0; i < 10; ++i) {
        printf("%5.1f", (numbers[i] - gemiddelde));
        if (i != 9) {
            printf(",");
        }
    }

    return 0;
}
