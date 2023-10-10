#include <stdio.h>
#include "functions.h"

int printscore(int player_score, int computer_score){
    printf("Score: You ");
    printf("%d", player_score);
    printf(", me ");
    printf("%d", computer_score);
    return 0;
}

int printresult(string player_choise, string computer_choise, string win_user){
    printf("You chose %s! \n", player_choise);
    printf("I chose %s! \n", computer_choise);

    if(win_user == "computer"){
        printf("I win! \n");
    } else{
        printf("I lose! \n");
    }
    return 0;
}


int main() {
    random_int(1, 10);
    int quit_program = 0;

    int computer_score = 0;
    int player_score = 0;

    while(quit_program != 1){
        char choise = read_char("Please enter your choice (r = rock, p = paper, s = scissors, q = quit): ");
        int computerchoise = random_int(1, 3);

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
            printf("It's a draw! \n");
            printscore(player_score, computer_score);
        }
        else if(choise == 'r' && computerchoise == 'p'){
            printresult("rock", "paper", "computer");

            computer_score++;
            printscore(player_score, computer_score);
        }
        else if(choise == 'r' && computerchoise == 's'){
            printresult("rock", "scissor", "user");

            player_score++;
            printscore(player_score, computer_score);
        }
        else if(choise == 'p' && computerchoise == 'r'){
            printresult("paper", "rock", "user");

            player_score++;
            printscore(player_score, computer_score);
        }
        else if(choise == 'p' && computerchoise == 's'){
            printresult("paper", "scissor", "computer");

            computer_score++;
            printscore(player_score, computer_score);
        }
        else if(choise == 's' && computerchoise == 'r'){
            printresult("scissor", "rock", "computer");

            computer_score++;
            printscore(player_score, computer_score);
        }
        else if(choise == 's' && computerchoise == 'p'){
            printresult("scissor", "paper", "user");

            player_score++;
            printscore(player_score, computer_score);
        }

        if(choise == 'q'){
            printf("%s", "Final score: \n");
            printscore(player_score, computer_score);
            quit_program = 1;
        }
        printf("\n");
    }



    return 0;
}
