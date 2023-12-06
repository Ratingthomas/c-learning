#include <stdio.h>
#include "functions.h"
#include "string.h"
#include "ctype.h"

/// Returns true if the given sentence is valid, and false otherwise.
/// A sentence is valid if it contains at least one non-whitespace character.
/// @param sentence The sentence to analyze.
/// @return True if the sentence is valid, false otherwise.
bool is_valid_sentence(const char * sentence){
    int white_space_amount = 0;
    char cset[] = "\0";

    white_space_amount = strcspn(sentence, cset);

    if(white_space_amount > 0){
        return true;
    } else{
        return false;
    }
}

int main() {
    int highest_num = 0;
    int lowest_num = 0;

    char longest[128];
    char shortest[128];

    bool loop = true;

    while (loop){
        char string[128];
        int count = 0;

        char * user_input = read_string("Please enter a sentence:");
        strncpy(string, user_input, 128);

        if((strcmp(user_input, "stop")) == 0){
            loop = false;
        } else{
            if(is_valid_sentence(user_input)){
                for (int i = 0; i < 128; ++i) {
                    if(string[i] != '\0'){
                        count++;
                    }
                }

                if(highest_num < count){
                    highest_num = count;
                    for (int i = 0; i < 128; ++i) {
                        longest[i] = string[i];
                    }
                } else if(lowest_num < count) {
                    lowest_num = count;
                    for (int i = 0; i < 128; ++i) {
                        shortest[i] = string[i];
                    }
                }
            } else{
                printf("Invalid input! \n");
            }

        }
    }

    printf("The longest sentence is: ");

    for (int i = 0; i < 128; ++i) {
        if(longest[i] != '\0'){
            printf("%c", longest[i]);
        }

    }

    printf("\nThe shortest sentence is: ");

    for (int i = 0; i < 128; ++i) {
        if(shortest[i] != '\0'){
            printf("%c", shortest[i]);
        }

    }

    return 0;
}
