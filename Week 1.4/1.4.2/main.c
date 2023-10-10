#include <stdio.h>
#include "functions.h"

int main() {
    float anwsers[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 10; i++) {
        float number = read_float("Enter a number (0 to stop)");

        if(number == 0){
            break;
        } else{
            anwsers[i] = number;
        }
    }

    for (int j = 0; j < 10; j++) {
        if(anwsers[j] != 0){
            printf("%.2f", (anwsers[j] * -1));
            printf(", ");
        }
    }

    return 0;
}
