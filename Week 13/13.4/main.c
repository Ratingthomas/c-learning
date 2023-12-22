#include <stdio.h>
#include "functions.h"
#include "string.h"

int main() {
    char * string[128];
    strncpy(string, read_string("Enter a sentence: "), 128);

    for (int i = 0; i < 128; ++i) {

    }

    return 0;
}
