#include <stdio.h>
#include "functions.h"

int main() {
    int num = read_int("Enter a number (1-99): ");

    int column_amount = 1;
    int local_count = 0;

    for (int count = 1; count <= num; ++count) {
        printf("%3d", count);
        local_count = local_count + 1;

        if(local_count == column_amount){
            column_amount = column_amount + 1;
            local_count = 0;
            printf("\n");
        }
    }

    return 0;
}
