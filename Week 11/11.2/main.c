#include <stdio.h>
#include "functions.h"
#include "ctype.h"
#include "string.h"

void encrypt(char * string, bool encoded, int shifted){
    char letters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; string[i] != '\0'; ++i) {
        int index = 0;

        if(string[i] != '\n' && isalpha(string[i])){
            for (int j = 0; j < 52; ++j) {
                if(string[i] == letters[j]){
                    index = j;

                }
            }
            if(encoded){
                index = (index + shifted) % 52;
                string[i] = letters[index];
            } else{
                index = index - shifted;
                while(index < 0){
                    index = index + 52;
                }
                string[i] = letters[index];
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
