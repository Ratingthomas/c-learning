#include <stdio.h>
#include "functions.h"
#include "string.h"
#include "ctype.h"

/// Removes all whitespace and punctuation from the given string.
/// @param string the string to remove whitespace and punctuation from
void remove_whitespace(char *string){
    char * tmp[128];

    for (int i = 0; i < 128; ++i) {
        if(isspace(string[i])){
            for (int j = i; j < 128; ++j) {
                string[j] = string[j+1];
            }
        }
    }

    for (int i = 0; i < 128; ++i) {
        if(ispunct(string[i])){
            for (int j = i; j < 128; ++j) {
                string[j] = string[j+1];
            }
        }
    }

}

int main() {
    char * input[128];

    strncpy(input, read_string("Enter a line of text: "), 128);

    remove_whitespace(input);

    printf("%s", input);

    return 0;
}