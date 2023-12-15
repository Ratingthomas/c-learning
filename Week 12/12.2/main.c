#include <stdio.h>
#include "string.h"
#include "functions.h"

/// Prints the array to the console, values comma-separated and on a single line
/// @param array The array to print.
/// @param length The length of the array.
void print_array(const int array[], int length){
    for (int i = 0; i < length; ++i) {
//        printf("[%d] at address %p\n", i, &array[i]);

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
    int index = 0;

    for (int i = 0; i < length; ++i) {
        if(array[i] < lowest){
            index = i;
            lowest = array[i];
        }
    }

    return &array[index];
}

/// Returns the address of the largest number in the array.
/// @param array The array to search.
/// @param length The length of the array.
/// @return The address of the largest number in the array, or NULL if the array is empty.
int* max_ptr(int array[], int length){
    int count = 0;
    int index_i = 1;

    for (int i = 0; i < length; ++i) {
        if(array[i] > count){
            count = array[i];
            index_i = i;
        }
    }

    return &array[index_i];
}

/// Swaps the values of the two integers pointed to by `a` and `b`.
/// @param a The memory address of the first integer.
/// @param b The memory address of the second integer.
void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
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

    printf("\nHet kleinste getal is: %d", *smallest);

    int * highest = max_ptr(random_ints, 10);

    printf("\nHet highest getal is: %d \n", *highest);

    swap(smallest, highest);

    print_array(random_ints, 10);



    return 0;
}
