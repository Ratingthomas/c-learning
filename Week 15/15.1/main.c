#include <stdio.h>
#include "functions.h"

/// Represents a point in 2D space.
typedef struct {
    int x; /// The x-coordinate of the point.
    int y; /// The y-coordinate of the point.
} point_t;

/// Represents a rectangle in 2D space.
typedef struct {
    point_t lower_left; /// The lower-left corner of the rectangle.
    point_t upper_right; /// The upper-right corner of the rectangle. Can't be to the left or below the lower-left corner.
} rectangle_t;

/// Generates a random point that has x and y coordinates between those of the given points
/// @param min the point with the minimum x and y coordinates
/// @param max the point with the maximum x and y coordinates
/// @returns a randomly generated point
point_t random_point(point_t min, point_t max){
    point_t new_point = {random_int(min.x, max.x), random_int(min.y, max.y)};
    return new_point;
}

/// Prints a point to the console.
/// @param point the point to print
void print_point(const point_t * point){
    printf("(%d, %d), ", point->x, point->y);
}

/// Prints a rectangle to the console.
/// @param rectangle the rectangle to print
void print_rectangle(const rectangle_t * rectangle){
    printf("\nEnclosing rectangle: (%d, %d) - (%d, %d)", rectangle->lower_left.x, rectangle->lower_left.y, rectangle->upper_right.x, rectangle->upper_right.y);
}

/// Gives the point that is the most lower-left of the two points.
/// @param point1 the first point
/// @param point2 the second point
/// @returns the point that is the most lower-left of the two points
const point_t * most_lower_left(const point_t * point1, const point_t * point2){
    point_t * tmp;

    if(point1->x > point2->x && point1->y > point2->y){
        tmp->x = point2->x;
        tmp->y = point2->y;
    }

    return tmp;
}

/// Gives the point that is the most upper-right of the two points.
/// @param point1 the first point
/// @param point2 the second point
/// @returns the point that is the most upper-right of the two points
const point_t * most_upper_right(const point_t * point1, const point_t * point2){
    point_t * tmp;

    if(point1->x < point2->x && point1->y < point2->y){
        tmp->x = point2->x;
        tmp->y = point2->y;
    }

    return tmp;
}


int main() {
    point_t points[10];
    point_t min = {0,0};
    point_t max = {50,50};

    point_t lower_left = {50, 50};
    point_t upper_right = {0, 0};

    rectangle_t rectangle = {lower_left, upper_right};

    printf("Points: ");
    for (int i = 0; i < 10; ++i) {
        points[i] = random_point(min, max);
        print_point(&points[i]);
    }

    // Get the most most_lower_left
    for (int i = 0; i < 10; ++i) {
        const point_t * value = most_lower_left(&lower_left, &points[i]);

        if(rectangle.lower_left.x > value->x && rectangle.lower_left.y > value->y){
            rectangle.lower_left.x = value->x;
            rectangle.lower_left.y = value->y;
        }
    }

    // Get the most_upper_right
    for (int i = 0; i < 10; ++i) {
        const point_t * value_n = most_upper_right(&upper_right, &points[i]);

        if(rectangle.upper_right.x < value_n->x && rectangle.upper_right.y < value_n->y){
            rectangle.upper_right.x = value_n->x;
            rectangle.upper_right.y = value_n->y;
        }
    }

    print_rectangle(&rectangle);

    return 0;
}
