#include <stdio.h>
#include "functions.h"
#include "thomas.h"

int main() {
    int date[3] = {0};
    bool invalid = true;

    while (invalid){
        read_date(date);

        if(check_date(date)){
            invalid = false;
        } else{
            printf("This date is invalid! \n");
        }
    }

    printf("%d-%d-%d is day %d of the year", date[0], date[1], date[2], day_in_year(date));
    return 0;
}
