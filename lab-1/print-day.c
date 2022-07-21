/*
    Program: print-day.c
    Author: Patricija
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

/*  Function: Main
    Parameters: int argc (argument count), char *argv[] an array of command-line arguments.
    Description:  Takes in an integer and prints out corresponding day.
*/

int main(int argc, char *argv[])
{   // Start of function.

    // Initialising variables.
    int day = atoi(argv[1]);

    // Initialising variables.
    char days[7][10] = { // 2D array with 7 rows the days, 9 columns as wednesday has longest char length of 9.
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
    };
    
    printf("%s\n", days[day - 1]);

    return(0);

} // End of function.