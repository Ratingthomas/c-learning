#include <stdio.h>
#include "functions.h"
#include "math.h"

typedef struct {
    int red;
    int green;
    int blue;
} colors_t;

// Read a color as a int from a user.
// @param prompt The message to display.
// @return void
int read_color(const char *prompt){
    printf("%s", prompt);
    int color;
    scanf("%d", &color);
    return color;
}

// Print the hex color
// @param color The color struct
// @return void
void print_color(const colors_t *color){
    printf("The color is: #%02x%02x%02x", color->blue, color->green, color->red);
}

// Increase hex color
// @param color The color struct
// @return void
void increase(colors_t *color){
    color->blue = round(color->blue / 0.7);
    color->green = round(color->green / 0.7);
    color->red = round(color->red / 0.7);
}

// Decrease hex color
// @param color The color struct
// @return void
void decrease(colors_t *color){
    color->blue = round(color->blue * 0.7);
    color->green = round(color->green * 0.7);
    color->red = round(color->red * 0.7);
}

int main() {
    colors_t colors;

    colors.blue = read_color("Enter blue component: ");
    colors.green = read_color("Enter green component: ");
    colors.red = read_color("Enter red component: ");

    print_color(&colors);

    char action = read_char("\nDo you want to increase (i) or decrease (d) the brightness (q to quit) ? ");

    while (action != 'q'){
        if(action == 'i'){
            increase(&colors);
            print_color(&colors);
        }
        else if(action == 'd'){
            decrease(&colors);
            print_color(&colors);
        }

        action = read_char("\nDo you want to increase (i) or decrease (d) the brightness (q to quit) ? ");
    }

    return 0;
}
