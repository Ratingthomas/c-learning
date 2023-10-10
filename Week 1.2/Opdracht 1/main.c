#include <stdio.h>
#include "functions.h"

int main() {
    float number = read_float("Please enter an integer: ");

    double radius = 3.14159265358979323846 * number * number;

    printf("The surface area of a circle with radius ");
    printf("%f", number);
    printf(" is ");
    printf("%.2f", radius);
    return 0;
}
