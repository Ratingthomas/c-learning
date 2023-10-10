#include <stdio.h>
#include "functions.h"

int printgrid(char grid_print[10][10]){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%3c", grid_print[i][j]);
        }
        printf("\n");
    }

    return 0;
}


int main() {
    char grid[10][10] = {
            {'.', '1', '2','3','4','5','6','7','8','9',},
            {'1', '.', '.','.','.','.','.','.','.','.',},
            {'2', '.', '.','.','.','.','.','.','.','.',},
            {'3', '.', '.','.','.','.','.','.','.','.',},
            {'4', '.', '.','.','.','.','.','.','.','.',},
            {'5', '.', '.','.','.','.','.','.','.','.',},
            {'6', '.', '.','.','.','.','.','.','.','.',},
            {'7', '.', '.','.','.','.','.','.','.','.',},
            {'8', '.', '.','.','.','.','.','.','.','.',},
            {'9', '.', '.','.','.','.','.','.','.','.',},
    };

    int treasure_row = random_int(0, 9);
    int treasure_column = random_int(0, 9);

    printf("Result: %d, %d \n", treasure_row, treasure_column);

    int gues = 0;

    while(gues != 1){
        printgrid(grid);

        int user_row = read_int("Enter row:");
        int user_column = read_int("Enter column:");

        if(user_row < 1 || user_row > 9 || user_column < 1 || user_column > 9){
            printf("Invalid input, please try again. \n");
        }
        else{
            if(treasure_row == user_row && treasure_column == user_column){
                gues = 1;
                grid[treasure_row][treasure_column] = 'x';
                printf("You found the treasure! \n");
            } else{
                int distance = max(user_row - treasure_row, treasure_row - user_row) + max(user_column - treasure_column, treasure_column - user_column);
                grid[user_row][user_column] = '+';

                printf("Not here! The treasure is %d squares away \n", distance);
            }
        }
    }

    printgrid(grid);
    return 0;
}
