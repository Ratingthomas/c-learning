#include <stdio.h>
#include "functions.h"

int main() {
    int number = read_int("Please enter a three-digit number: ");

    if(number > 999 || number < 100){
        printf("Sorry, that's not a three-digit number! Aborting... \n");
        //main();
        return 0;
    }

    int first_num = number % 10;
    int second_num = (number / 10) % 10;
    int third_num = (number / 100) % 10;

    printf("%d", first_num);
    printf("%d", second_num);
    printf("%d", third_num);

    printf("\n");

    main();
    return 0;
}
