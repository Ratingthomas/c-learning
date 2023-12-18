#include <stdio.h>
#include "string.h"
#include "functions.h"
#include "ctype.h"

/// Counts the number of words in the given sentence.
/// @param sentence the sentence to count the words in
/// @returns the number of words in the sentence
int count_words(const char *sentence){
    int count = 0;

    for (int i = 0; i < 128; ++i) {
        if (isalpha(*sentence)) {
            while (isalpha(*sentence) || ispunct(*sentence)) {
                sentence++;
            }
            count++;
        }
        else if (isnumber(*sentence)) {
            while (isnumber(*sentence)) {
                sentence++;
            }
            count++;
        }
        else sentence++;
    }

    return count;
}

int main() {
    char * sentence[128];
    strncpy(sentence, read_string("Enter a line of text: "), 128);

    while (sentence[0] != NULL){
        printf("Amount of words: %d\n", count_words(sentence));

        strncpy(sentence, read_string("Enter a line of text: "), 128);
    }

    printf("Exiting program. Have a nice day!");
    return 0;
}
