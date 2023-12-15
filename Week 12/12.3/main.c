#include <stdio.h>
#include "functions.h"
#include "string.h"

/// Swaps the two strings if the first string is alphabetically larger than the second string.
/// @param a The memory address of the first string.
/// @param b The memory address of the second string.
void sort_two_strings(const char ** a, const char ** b){
    int return_value = strcmp(a, b);

    if(return_value > 0){
        char * tmp;
        strncpy(tmp, a, 128);
        strncpy(a, b, 128);
        strncpy(b, tmp, 128);
    }
}

int main() {
    char * data[3][128];

    strncpy(data[0], read_string("First: "), 128);
    strncpy(data[1], read_string("Second: "), 128);
    strncpy(data[2], read_string("Third: "), 128);

    sort_two_strings(data[0], data[1]);
    sort_two_strings(data[1], data[2]);
    sort_two_strings(data[0], data[1]);

    for (int i = 0; i < 3; ++i) {
        printf("%s \n", data[i]);
    }

    return 0;
}
