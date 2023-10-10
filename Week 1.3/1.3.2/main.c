#include <stdio.h>
#include "functions.h"

int main() {
    int loop = 0;

    int second_highest = 0;
    int highest = 0;
    int first_run = 0;
    int numbercount = 0;

    int usernumber = read_int("Please enter a number: ");
    while (usernumber != 0){

//        if(usernumber != 0){
            numbercount++;
//        }

//        if(usernumber == 0){
//        }

        if(first_run == 0){
            highest = usernumber;
            first_run = 1;
        } else{
            if(second_highest == 0 && usernumber < highest){
                second_highest = usernumber;
            }
            else if(usernumber > highest){
                second_highest = highest;
                highest = usernumber;
            }
//            printf("Usernumber: %d \n", usernumber);
//            printf("highest: %d \n", highest);
//            printf("second_highest: %d \n", second_highest);
        }


        usernumber = read_int("Please enter a number: ");
    }
    if(numbercount < 2){
//        printf("Not enough numbers were entered");
        loop++;
    } else{
        printf("%d", second_highest);
//        loop++;
        //return 0;
    }

    return 0;
}
