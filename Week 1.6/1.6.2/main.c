#include <stdio.h>
#include "math.h"
#include "functions.h"

/// Asks the user to enter a valid operator, and returns the operator.
/// Valid operators are: +, -, *, /, ^ (exponentiation)
/// If the user enters an invalid operator, the user is asked again until a valid operator is entered.
/// @return The operator entered by the user.
char read_operator(void){
    char operator = 0;
    while (operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '^'){
        operator = read_char("Please enter an operator: ");
    }

    return operator;
}

bool perform_another_calculation(void){
    char return_char = read_char("Do you want to perform another calculation? (y/n): ");
    if(return_char == 'y'){
        return true;
    }
    else{
        return false;
    }
}

/// Returns the result of applying the given operator to the given numbers.
/// @param number1 The first number.
/// @param number2 The second number.
/// @param operator The operator.
/// @return The result of applying the operator to the two numbers.
float apply_operator(float number1, float number2, char operator){
    if(operator == '+'){
        return number1 + number2;
    } else if(operator == '-'){
        return number1 - number2;
    } else if(operator == '^'){
        return powf(number1, number2);
    } else if(operator == '/'){
        return number1 / number2;
    } else if(operator == '*'){
        return number1 * number2;
    }
}

int main() {
    int first_run = true;

    while (first_run || perform_another_calculation()){
        first_run = false;

        float num1 = read_float("Please enter a number: ");
        float num2 = read_float("Please enter another number: ");

        char operator = read_operator();

        float result = apply_operator(num1, num2, operator);
        printf("%.4f %d %.4f = %.4f \n", num1, operator, num2, result);
    }

    return 0;
}
