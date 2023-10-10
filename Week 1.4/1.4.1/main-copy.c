#include <stdio.h>
#include "functions.h"

int main() {
    int times = read_int("How many times should the dice be rolled?");

    int dice_numbers[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int results[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i <= times; i++) {
        int result = random_int(2, 12);

        for (int j = 2; j <= 12; j++) {
            if(j == result){
                //printf("%d", result);
                results[(j-2)] = results[(j-2)] + 1;
            }
        }
    }

    for (int i = 0; i <= 10; ++i) {
        printf("%d: %d \n", i+2, results[i]);
    }

//    printf("2: %d \n", results[0]);
//    printf("3: %d \n", results[1]);
//    printf("4: %d \n", results[2]);
//    printf("5: %d \n", results[3]);
//    printf("6: %d \n", results[4]);
//    printf("7: %d \n", results[5]);
//    printf("8: %d \n", results[6]);
//    printf("9: %d \n", results[7]);
//    printf("10: %d \n", results[8]);
//    printf("11: %d \n", results[9]);
//    printf("12: %d \n", results[10]);

    return 0;
}
