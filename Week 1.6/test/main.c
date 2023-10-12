#include <stdio.h>

int plus(int test){
    test = test + 1;
    return test;
}

int main() {
    int test = 0;

    int new = plus(1);
    printf("%d", new);

    printf("Hello, World!\n");
    return 0;
}
