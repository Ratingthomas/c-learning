#include <stdio.h>
#include "functions.h"
#include "ctype.h"
#include "string.h";

int main() {
    printf("Hello, World!\n");

    int klinker_amount = 0;
    int medeklinker_amount = 0;
    int nummers_amount = 0;

    char input[80];

    char klinkers[5] = {'a', 'e', 'i', 'o', 'u'};

    char * text = read_string("Please enter a sentence: ");
    strncpy(input, text, 80);

    for (int i = 0; i < 80; ++i) {
        if(input[i] != ""){
            printf("%c", text[i]);
        }
    }

    return 0;
}
