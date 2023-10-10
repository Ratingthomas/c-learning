#include <stdio.h>
#include "functions.h"

int main() {
    random_int(1, 10);
    char choise = read_char("Please enter your choice (r = rock, p = paper, s = scissors): ");
    int computerchoise = random_int(1, 3);
//    printf("%d", computerchoise + '\n');

    if(computerchoise == 1){
        computerchoise = 'r';
    }
    else if(computerchoise == 2){
        computerchoise = 'p';
    }
    else if(computerchoise == 3){
        computerchoise = 's';
    }

    if(choise == computerchoise){
        printf("It's a draw!");
    }
    else if(choise == 'r' && computerchoise == 'p'){
        printf("You chose rock! \n");
        printf("I chose paper! \n");
        printf("I win!");
    }
    else if(choise == 'r' && computerchoise == 's'){
        printf("You chose rock! \n");
        printf("I chose scissor! \n");
        printf("I lose!");
    }
    else if(choise == 'p' && computerchoise == 'r'){
        printf("You chose paper! \n");
        printf("I chose rock! \n");
        printf("I lose!");
    }
    else if(choise == 'p' && computerchoise == 's'){
        printf("You chose paper! \n");
        printf("I chose scissor! \n");
        printf("I win!");
    }
    else if(choise == 's' && computerchoise == 'r'){
        printf("You chose scissor! \n");
        printf("I chose rock! \n");
        printf("I win!");
    }
    else if(choise == 's' && computerchoise == 'p'){
        printf("You chose scissor! \n");
        printf("I chose paper! \n");
        printf("I lose!");
    }

    printf("\n\n");
    main();

    return 0;
}
