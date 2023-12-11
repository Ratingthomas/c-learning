#include <stdio.h>
#include "string.h"
#include "functions.h"

/// Prints the array to the console, values comma-separated and on a single line
/// @param array The array to print.
/// @param length The length of the array.
void print_array(const int array[], int length){
    for (int i = 0; i < length; ++i) {
        if(length - i != 1){
            printf("%i, ", array[i]);
        } else{
            printf("%i", array[i]);
        }
    }
}

/// Returns the address of the smallest number in the array.
/// @param array The array to search.
/// @param length The length of the array.
/// @return The address of the smallest number in the array, or NULL if the array is empty.
int* min_ptr(int array[], int length){
    int lowest = 101;
    int index;

    for (int i = 0; i < length; ++i) {
        if(array[i] < lowest){
            index = i;
            lowest = array[i];
        }
    }

    return &index;
}

/// Returns the address of the largest number in the array.
/// @param array The array to search.
/// @param length The length of the array.
/// @return The address of the largest number in the array, or NULL if the array is empty.
int* max_ptr(int array[], int length){
    int highest = -1;
    int index;

    for (int i = 0; i < length; ++i) {
        if(array[i] < highest){
            index = i;
            highest = array[i];
        }
    }

    return &index;
}


int main() {
    int random_ints[10] = {
            random_int(0, 100),
            random_int(0, 100),
            random_int(0, 100),
            random_int(0, 100),
            random_int(0, 100),
            random_int(0, 100),
            random_int(0, 100),
            random_int(0, 100),
            random_int(0, 100),
            random_int(0, 100),
    };

    print_array(random_ints, 10);
    int * smallest = min_ptr(random_ints, 10);
    int * highest = max_ptr(random_ints, 10);

    printf("\nHet kleinste getal is: %d", random_ints[*smallest]);
    printf("\nHet highest getal is: %d", random_ints[*highest]);

    return 0;
}
