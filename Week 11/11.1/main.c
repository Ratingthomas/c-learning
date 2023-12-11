#include <stdio.h>
#include "functions.h"
#include "ctype.h"
#include "string.h"

int main() {
    bool loop = true;

    while (loop){
        int klinker_amount = 0;
        int medeklinker_amount = 0;
        int nummers_amount = 0;

        char input[128];

        char klinkers[5] = {'a', 'e', 'i', 'o', 'u'};
        char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

        char * inputText = read_string("Please enter a sentence: ");
        strncpy(input, inputText, 128);

        if(input[0] == '\0'){
            loop = false;
            printf("Bye!");
        }

        if(loop){
            for (int i = 0; i < 128; ++i) {
                if(input[i] != '\0'){
                    if(isalpha(input[i])){
                        bool klinker_found = false;

                        for (int j = 0; j < 5; ++j) {
                            if(klinkers[j] == tolower(input[i])){
                                klinker_found = true;
                            }
                        }

                        if(klinker_found){
                            klinker_amount++;
                        } else{
                            medeklinker_amount++;
                        }
                    }

                    for (int j = 0; j < 10; ++j) {
                        if(input[i] == numbers[j]){
                            nummers_amount = nummers_amount + 1;
                        }
                    }
                }
            }

            printf("Klinkers: %d", klinker_amount);
            printf("\nMedeklinkers: %d", medeklinker_amount);
            printf("\nNummers: %d \n", nummers_amount);
        }

    }

    return 0;
}
