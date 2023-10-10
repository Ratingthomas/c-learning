#include <stdio.h>
#include "functions.h"

int main() {
    int times = read_int("How many times should the dice be rolled?");
    int results[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < times; ++i) {
        int result = random_int(2, 12);

        results[result-2] = results[result-2] + 1;
    }

    for (int i = 0; i <= 10; ++i) {
        printf("%d: %d \n", i+2, results[i]);
    }

    return 0;
}