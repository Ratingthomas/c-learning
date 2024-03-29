//
// Created by Thomas Levels on 12/10/2023.
//

#include <stdio.h>
#include "functions.h"

void read_date(int array[]){
    array[0] = read_int("Please enter a day: ");
    array[1] = read_int("Please enter a month: ");
    array[2] = read_int("Please enter a year: ");
}

bool leap_year(int year){
    bool divisible_by_4 = year % 4 == 0;    // check if year is divisible by 4
    bool divisible_by_100 = year % 100 == 0;    // check if year is divisible by 100
    bool divisible_by_400 = year % 400 == 0;    // check if year is divisible by 400
    bool leap_year = divisible_by_4 && (!divisible_by_100 || divisible_by_400); // check if year is a leap year
    return leap_year;
}

int number_of_days(int month, int year){
    if(month == 2){
        if(leap_year(year)){
            return 29;
        } else{
            return 28;
        }
    } else if(month <= 7){
        if(month % 2 == 0){
            return 30;
        } else if(month % 2 == 1){
            return 31;
        }
    } else{
        if(month % 2 == 0){
            return 31;
        } else if(month % 2 == 1){
            return 30;
        }
    }
}

bool check_date(int array[]){
    if(array[0] < 0 || array[1] < 0 || array[2] < 0){
        return false;
    }

    if(array[0] > number_of_days(array[1], array[2])){
        return false;
    }
    else if(array[1] > 12){
        return false;
    }
    else{
        return true;
    }
}

int day_in_year(int date[]){
    int dates = date[0];

    for (int i = 1; i < date[1]; ++i) {
        dates = dates + number_of_days(i, date[2]);
    }

    return dates;
}

int difference(int current_date_amount, int birth_day, int current_date[], int date[]){
    int dates_in_year = 365;

    if(leap_year(date[2])){
        dates_in_year = 366;
    }

    int year_difference = (current_date[2] - date[2]) * dates_in_year;
    int days_difference = (current_date_amount - birth_day);

    return year_difference + days_difference;
}