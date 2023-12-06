#include <stdio.h>
#include "functions.h"
#include "ctype.h"
#include "string.h"

int main() {
    int klinker_amount = 0;
    int medeklinker_amount = 0;
    int nummers_amount = 0;

    char input[80];

    char klinkers[5] = {'a', 'e', 'i', 'o', 'u'};
    char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    char * inputText = read_string("Please enter a sentence: ");
    strncpy(input, inputText, 80);

    for (int i = 0; i < 80; ++i) {
        printf("%c", input[i]);

        for (int j = 0; j < 26; ++j) {
            bool medeklinker_found = false;


        }

        for (int j = 0; j < 10; ++j) {
            if(input[i] == numbers[j]){
                nummers_amount = nummers_amount + 1;
            }
        }

    }

    printf("\nKlinkers: %d", klinker_amount);
    printf("\nMedeklinkers: %d", medeklinker_amount);
    printf("\nNummers: %d", nummers_amount);
    return 0;
}
