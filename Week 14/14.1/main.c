#include <stdio.h>
#include "functions.h"
#include "math.h"

typedef struct {
    int x;
    int y;
} coordinate_t;

// Uses the console to read a coordinate from the user.
/// @param prompt The prompt to display to the user.
/// @return The coordinate entered by the user.
coordinate_t read_coordinate(const char *prompt){
    printf("Enter coordinate: ");
    coordinate_t coord;

    scanf("%d, %d", &coord.x, &coord.y);

    return coord;
}

// Calculates the distance between two coordinates.
/// @param a The first coordinate.
/// @param b The second coordinate.
/// @return The distance between the two coordinates.
float distance(const coordinate_t *a, const coordinate_t *b){
    return sqrt(pow((b->x - a->x), 2) + pow((b->y - a->y), 2));
}

int main() {
    printf("Hello, World!\n");

    coordinate_t coord_1;
    coordinate_t coord_2;

    coord_1 = read_coordinate("Enter first coordinate");
    coord_2 = read_coordinate("Enter second coordinate");

    double distance_int = distance(&coord_1, &coord_2);

    printf("The distance between (%d, %d) and (%d, %d) is %.2f", coord_1.x, coord_1.y, coord_2.x, coord_2.y, distance_int);

    return 0;
}
