#include <stdio.h>
#include "functions.h"
#include "ctype.h"
#include "string.h"

void encrypt(char * string, bool encoded, int shifted){
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < 128; ++i) {
        int index = 0;

        if(string[i] != '\n' && isalpha(string[i])){
            for (int j = 0; j < 52; ++j) {
                if(string[i] == letters[j]){
                    index = j;
                    if(index == 51){
                        index = 0;
                    }
                }
            }
            if(encoded){
                string[i] = letters[index + shifted];
            } else{
                string[i] = letters[index - shifted];
            }
        }

        shifted++;
    }

}

int main() {
    char * sentence = read_string("Please enter a sentence: ");
    int shifted = 1;

    char input[128];

    strncpy(input, sentence, 128);

    encrypt(input, true, shifted);
    printf("Encrypted text: %s\n", input);
    encrypt(input, false, 1);

    printf("Decoded sentence: %s", input);
    return 0;
}
