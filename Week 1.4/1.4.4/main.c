#include <stdio.h>
#include "functions.h"

int printgrid(char grid_print[10][10]){
    for (int i = 0; i <= 9; ++i) {
        for (int j = 0; j <= 9; ++j) {
            printf("%3c", grid_print[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int main() {
    char grid[10][10] = {
            {'+', '1', '2','3','4','5','6','7','8','9',},
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

    int treasure_result_row = random_int(1, 9);
    int treasure_result_colomn = random_int(1, 9);

    printf("Result: %d, %d \n", treasure_result_row, treasure_result_colomn);

    int userGuesRow = 0;
    int userGuesColomn = 0;

    while(treasure_result_row != userGuesRow){
        printgrid(grid);

        userGuesRow = read_int("Enter row:");
        userGuesColomn = read_int("Enter column:");

        if(userGuesRow < 1 || userGuesRow > 9 || userGuesColomn < 1 || userGuesColomn > 9){
            printf("Invalid input, please try again. \n");
        }
        else{
            int distance = max(userGuesRow - treasure_result_row, treasure_result_row - userGuesRow) + max(userGuesColomn - treasure_result_colomn, treasure_result_colomn - userGuesColomn);
            grid[userGuesRow][userGuesColomn] = '+';

            if(treasure_result_row != userGuesRow && treasure_result_colomn != userGuesColomn){
                printf("Not here! The treasure is %d squares away \n", distance);
            }
        }
    }

    grid[treasure_result_row][treasure_result_colomn] = 'x';
    printf("You found the treasure! \n");

    printgrid(grid);
    return 0;
}
