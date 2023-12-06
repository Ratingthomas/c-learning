#include <stdio.h>
#include "ctype.h"
#include "functions.h"
#include "string.h"

/// Returns the frequency of each letter in the given sentence.
/// @param sentence The sentence to analyze.
/// @param frequencies An array of 26 integers, where the frequency of each letter is stored.
void get_letter_frequencies(const char * sentence, int frequencies[static 26]){
    int count = 97;

    for (int i = 0; i < 128; ++i) {
        for (int j = 0; j < 26; ++j) {
            if(tolower(sentence[i]) == count && isalpha(sentence[i])){
                frequencies[j]  = frequencies[j] + 1;
            }
            count++;
        }
        count = 97;
    }
}

/// Returns the index of the letter with the highest frequency in the given array.
/// @param frequencies An array of 26 integers, where the frequency of each letter is stored.
/// @return The index of the letter with the highest frequency.
int get_highest_frequency_index(int frequencies[static 26]){
    int highest = 0;
    int index = 0;

    for (int i = 0; i < 26; ++i) {
        if(frequencies[i] > highest){
            highest = frequencies[i];
            index = i;
        }
    }

    return index;
}

/// Prints the letter frequencies to the console. Modified the frequencies array by setting the frequency of each letter to zero after printing it.
/// @param frequencies An array of 26 integers, where the frequency of each letter is stored.
void print_letter_frequencies(int frequencies[static 26]){
//    printf("%i \n", );
//    get_highest_frequency_index(frequencies)

    int letter = 97;
    for (int i = 0; i < 26; ++i) {
        if(frequencies[i] != 0){
            printf("%c: %i \n", letter, frequencies[i]);
        }
        letter++;
    }
}

int main() {
    char sentence[128];
    int frequencies[26] = {};

    char * input = read_string("Please enter a sentence");
    strncpy(sentence, input, 128);

    get_letter_frequencies(sentence, frequencies);

    print_letter_frequencies(frequencies);


    return 0;
}
