#include <stdio.h>
#include "functions.h"

int main() {
    random_int(1, 2);
    printf("Welcome to the pretzel game! \n");

    int pretzels = 0;

    while(pretzels < 10 || pretzels > 50) {
        pretzels = read_int("How many pretzels are in the pile? (10-50) ");

        if(pretzels < 10 || pretzels > 50){
            printf("Invalid input, try again! \n");
        }
    }

    int startplayer = random_int(1, 2);

    if(startplayer == 1){
        printf("The player starts \n");
    }
    else if(startplayer == 2){
        printf("The computer starts \n");
    }

    while (pretzels != 0){
        printf("There are %i pretzels in the pile. \n", pretzels);

        int max = 3;

        if(pretzels <= 3){
            max = pretzels;
        }

        random_int(1, max);

        if(startplayer == 1){
            int remove = read_int("How many pretzels do you want to remove (1-3)? ");\

            if(remove > 3){
                printf("Invalid input, try again! \n");
            }
            else if(remove < 0){
                printf("Invalid input, try again! \n");
            }else{
                pretzels = pretzels - remove;

                if(pretzels == 0){
                    printf("Player lose");
                }
                startplayer++;
            }
        }
        else if(startplayer == 2){
            int computer_remove = random_int(1, max);

            printf("I remove %i \n", computer_remove);

            pretzels = pretzels - computer_remove;

            if(pretzels == 0){
                printf("I lose");
            }

            startplayer--;
        }
    }

    return 0;
}
