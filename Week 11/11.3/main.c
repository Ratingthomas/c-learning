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

        char * user_input = read_string("Please enter a sentence:");
        strncpy(string, user_input, 128);

        if((strcmp(user_input, "stop")) == 0){
            loop = false;
        } else{
            if(is_valid_sentence(user_input)){
                unsigned long length = strlen(user_input);

                if(length > highest_num){
                    highest_num = length;
                    strcpy(longest, user_input);
                    if(lowest_num == 0){
                        lowest_num = length;
                        strcpy(longest, user_input);
                    }
                } else if(length < lowest_num){
                    lowest_num = length;
                    strcpy(shortest, user_input);
                }

            } else{
                printf("Invalid input! \n");
            }

        }
    }

    printf("The shortest sentence is: %s\n", longest);
    printf("The longest sentence is: %s", shortest);

    return 0;
}
