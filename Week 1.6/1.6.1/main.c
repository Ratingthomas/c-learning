#include <stdio.h>
#include "functions.h"

/// Fills the given array with random integer numbers between min and max (inclusive).
/// @param array The array to fill.
/// @param size The size of the array (i.e., number of elements).
/// @param min The minimum value of the random numbers.
/// @param max The maximum value of the random numbers.
void fill_array(int array[], int size, int min, int max){
    for (int i = 0; i < size; ++i) {
        array[i] = random_int(min, max);
    }
}

/// Prints the contents of the given array to the console, comma-separated and on a single line.
/// @param array The array to print.
/// @param size The size of the array (i.e., number of elements).
void print_array(int array[], int size){
    for (int i = 0; i < size; ++i) {
        printf("%3d", array[i]);
    }
}

/// Reverses the contents of the given array.
/// @param array The array to reverse.
/// @param size The size of the array (i.e., number of elements).
void reverse_array(int array[], int size){
    int temp_array[10] = { 0 };

    for (int i = 0; i < size; ++i) {
        temp_array[i] = array[size - i - 1];
    }

    for (int i = 0; i < size; ++i) {
        array[i] = temp_array[i];
    }
}

int main() {
    int numbers[10] = { 0 };

    fill_array(numbers, 10, 1, 10);

    printf("The array contains: ");
    print_array(numbers, 10);

    reverse_array(numbers, 10);

    printf("\nThe array : ");
    print_array(numbers, 10);
    return 0;
}
