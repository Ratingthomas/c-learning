#include <stdio.h>
#include "functions.h"
#include <math.h>

int main() {
    float pay_amount = read_float("Please enter the amount of money that you pay: ");
    float product_price = read_float("Please enter the price of the product: ");

    float change = (pay_amount - product_price) * 100;
    int change_cents = (int) round(change);

    printf("You get back ");
    printf("%d", change_cents);
    printf(" cents in change.");

    int cent = 50;
    int amount = 0;

    while (cent != -1){
        int over = (change_cents - cent);

        if(over < 0){
            if(amount != 0){
                printf("\n");
                printf("%d", amount);
                printf(" munt(en) van ");
                printf("%d", cent);
                printf(" cents");
            }

            amount = 0;

            if(cent == 50){
                cent = 20;
            }
            else if(cent == 20){
                cent = 10;
            }
            else if(cent == 10){
                cent = 5;
            }
            else if(cent == 5){
                cent = 2;
            }
            else if(cent == 2) {
                cent = 1;
            }
            else if(cent == 1) {
                cent = 0;
            }
        }
        else if(cent == 0){
            cent = -1;
        }
        else{
            amount = amount + 1;
            change_cents = change_cents - cent;
        }
    }


    return 0;
}
