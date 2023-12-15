#include <stdio.h>
#include "functions.h"
#include "string.h"
#include "ctype.h"
#include "math.h"


/// Checks if the string contains a valid coordinate in the form (x, y).
/// @param string The string to check.
/// @param x The memory address of the integer to store the x-component of the coordinate in.
/// @param y The memory address of the integer to store the y-component of the coordinate in.
/// @return `true` if the string contains a single integer, `false` otherwise.
bool read_coordinate(const char *string, int *x, int *y){
    int n = sscanf(string, "(%f,%f)", &x, &y);

    if(n != 2){
        return false;
    } else{
        return true;
    }

}

int main() {
    bool invalid_1 = true;
    bool invalid_2 = true;

    char coordinates_1[128];
    char coordinates_2[128];

    int * x_1 = 0;
    int * y_1 = 0;

    int * x_2 = 0;
    int * y_2 = 0;

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

    while (invalid_2){
        char * input_2 = read_string("Please enter a coordinate: ");
        strncpy(coordinates_2, input_2, 128);

        if(read_coordinate(coordinates_2, x_2, y_2)){
            printf("Valid coordinate");
            invalid_2 = false;
        }
        else{
            printf("Invalid coordinate\n");
        }
    }

//    float distance = sqrt((powf((x_2 - x_1), 2.0) + powf((*y_2 - *y_1), 2.0)));
//    float distance = *x_2;
    printf("\n the distance is: %p", x_2);


    return 0;
}
