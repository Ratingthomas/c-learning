#include <stdio.h>
#include "functions.h"

int main() {
    // 20 random tussen de 0 en 9 getallen genereren + in een array zetten.
    int numbers[20] = {0};
    for (int i = 0; i < 20; ++i) {
        numbers[i] = random_int(0, 9);
    }

    int newnumbers[20] = {0};

    for (int i = 0; i < 20; ++i) {
        printf("%d", numbers[i]);
        if(i != 19){
            printf(", ");
        }
    }

    int arraycount = 0;

    for (int i = 0; i < 20; ++i) {
        // Checken of het getal niet 0 is, dan in de nieuwe array gooien.
        if(numbers[i] != 0) {
            newnumbers[arraycount] = numbers[i];
            arraycount++;
        }
    }

    printf("\n");

    for (int i = 0; i < 20; ++i) {
        printf("%d", newnumbers[i]);
        if(i != 19){
            printf(", ");
        }
    }

    return 0;
}
