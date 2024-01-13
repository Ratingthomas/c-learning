#include <stdio.h>

int main() {
    printf("Hello, World!\n");

    int code = 19;

    int codes[] = {
            code % 10,
            (code / 10),
    };

    printf("%d \n%d", codes[0], codes[1]);

    return 0;
}
