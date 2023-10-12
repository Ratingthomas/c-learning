#include <stdio.h>
#include "functions.h"
#include "thomas.h"

int main() {
    int current_date[3] = {0};

    get_current_date(current_date);

    printf("Current date: %d-%d-%d \n", current_date[0], current_date[1], current_date[2]);
    printf("Please enter your date of birth: \n");

    bool invalid = true;
    int date[3] = {0};

    while (invalid){
        read_date(date);

        if(check_date(date)){
            invalid = false;
        } else{
            printf("This date is invalid! \n");
        }
    }

    int current_date_amount = day_in_year(current_date);
    int birth_day = day_in_year(date);
    printf("%d", difference(current_date_amount, birth_day, current_date, date));

    return 0;
}