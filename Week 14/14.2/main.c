#include <stdio.h>
#include "functions.h"
#include "math.h"

typedef struct {
    int red;
    int green;
    int blue;
} colors_t;

int read_color(const char *prompt){
    printf("%s", prompt);
    int color;
    scanf("%d", &color);
    return color;
}

void print_color(const colors_t *color){
    printf("The color is: #%02x%02x%02x", color->blue, color->green, color->red);
}

colors_t increase(const colors_t *color){


    return *color;
}

int main() {
    colors_t colors;

    colors.blue = read_color("Enter blue component: ");
    colors.green = read_color("Enter green component: ");
    colors.red = read_color("Enter red component: ");

    print_color(&colors);

    char action = read_char("Do you want to increase (i) or decrease (d) the brightness (q to quit) ? ");

    while (action != 'q'){
        if(action == 'i'){
            colors = increase(&colors);
            print_color(&colors);
        }

        action = read_char("Do you want to increase (i) or decrease (d) the brightness (q to quit) ? ");
    }


    return 0;
}
