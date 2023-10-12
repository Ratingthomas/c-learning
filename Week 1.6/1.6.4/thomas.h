#include <stdio.h>
//
// Created by Thomas Levels on 12/10/2023.
//

#ifndef INC_1_6_3_THOMAS_H
#define INC_1_6_3_THOMAS_H

//// Ask the user to enter the current date and store it in a array.
//// @param array The date array
void read_date(int array[]);

// Check if the year is a leap year.
// @params year The year
// @return true if year is a leap year, otherwise false.
bool leap_year(int year);

// Calculate the number of days in month, on a specific year.
// @params month The month
// @params year The year.
// @return the number of days.
int number_of_days(int month, int year);

int day_in_year(int date[]);

// Check if the date given is valid.
// @param array The date array.
bool check_date(int array[]);

int difference(int current_date_amount, int birth_day, int current_date[], int date[]);

#endif //INC_1_6_3_THOMAS_H
