#include <stdio.h>
#include "functions.h"
#include "string.h"
#include "ctype.h"
#include "regex.h"


/// Checks if the string contains a valid coordinate in the form (x, y).
/// @param string The string to check.
/// @param x The memory address of the integer to store the x-component of the coordinate in.
/// @param y The memory address of the integer to store the y-component of the coordinate in.
/// @return `true` if the string contains a single integer, `false` otherwise.
bool read_coordinate(const char *string, int *x, int *y){
    bool good = true;
    char * specials = "[@_!#$%^&*<>?/|}{~:]";

    for (int i = 0; i < 128; ++i) {
        if(isalpha(string[i])){
            good = false;
        }

        for (int j = 0; j < 20; ++j) {
            if(string[i] == specials[j]){
                good = false;
            }
        }

    }

    return good;
}

int main() {
    bool invalid_1 = true;
    bool invalid_2 = true;

    char coordinates_1[128];
    char coordinates_2[128];

    int * x_1 = 0;
    int * y_1 = 0;

    while (invalid_1){
        char * input_1 = read_string("Please enter a coordinate: ");
        strncpy(coordinates_1, input_1, 128);

        if(read_coordinate(coordinates_1, x_1, y_1)){
            printf("Valid coordinate");
            invalid_1 = false;
        }
        else{
            printf("Invalid coordinate\n");
        }
    }


    return 0;
}
