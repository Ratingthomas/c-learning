#include <stdio.h>
#include "functions.h"
#include "ctype.h"
#include "string.h"

char character(char alphabet[], char input, int shifted, bool next){
    int index = 0;

    for (int j = 0; j < 52; ++j) {
        if(alphabet[j] == input){
            index = j;
        }
    }

    if(next == true){
        if(index == 51){
            index = -1 + shifted;
        } else{
            index = index + shifted;
        }
    }


    return alphabet[index];
}

int main() {
    char alphabet[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char * sentence = read_string("Please enter a sentence: ");
    int shifted = 1;

    char input[128];
    char encoded[128];
    char decoded[128];

    strncpy(input, sentence, 128);

    for (int i = 0; i < 128; ++i) {
        if(isalpha(input[i])){
            char new = character(alphabet, input[i], shifted, true);
            shifted = shifted + 1;
            encoded[i] = new;
        } else{
            encoded[i] = input[i];
        }
    }

    printf("Encoded sentence: %s \n", encoded);
    printf("Decoded sentence: %s", decoded);
    return 0;
}
