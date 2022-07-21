// Includes.

#include <stdio.h>
#include <stdlib.h>

/*
Name: leap-year.c
Functions: Main, isLeap
Parameters: Two years
Returns: int
Description: Takes in two years, a start and end, and prints all leap years within the range given.
Author: Patricija Shalkauskaite
*/

// Initialising function.
int isLeap(int year);

int main(int argc, char * argv[])
{   // Start of main function.

    // Defining variables.
    int year1 = atoi(argv[1]);
    int year2 = atoi(argv[2]);

    while(year1 <= year2)  // Stop when we've reached the second year specified.
    {
        isLeap(year1);
        year1 += 1;
    }

    return(0);
}

// Building initialised function.
int isLeap(int year)
{
    if(year % 100 == 0)  // Checks to see if it's a century we're dealing with.
    {
        if((year % 400 == 0) && (year % 4 == 0))  // Centuries are leap years if they are both divisible by 400 and 4.
        {
           printf("%d\n", year); 
        }
    }
    else if((year % 4 == 0))  // Else it'll just be a normal year to check.
    {
        printf("%d\n", year);
    }
    
}
