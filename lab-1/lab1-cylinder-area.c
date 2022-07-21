
/*
    Program: cylinder-area.c
    Author: Patricija
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

/*  Function: Main
    Parameters: int argc (argument count), char *argv[] an array of command-line arguments.
    Description:  Takes radius and height input and prints out cylinder area.
*/

// Defining pi.
#define PI 3.1415

int main(int argc, char *argv[1])
{   // Start of function.   

    // Initalising variables.
    int radius = 0;
    int height = 0;
    float area = 0.0;

    if (argc == 1)  // If the argument count is only 1, that's the program name with no other arguments given.
    {
        printf("No input given!\n");
        return(0);
    }

    radius = atoi(argv[1]);

    int radius_sqrd = radius * radius;

    if (argc == 2)  // If argument count is 2, then that's the program name and the radius, but no height.
    {
        printf("Two arguments needed!\n");
        return(0);
    }

    height = atoi(argv[2]);

    area = (2 * PI * radius * height) + (2 * PI * radius_sqrd);  // Surface area of cylinder formula.

    if ((height < 0) || (radius < 0))  // Checking if height or radius inputted is a negative number.
    {
        printf("The radious or height cannot be negative!\n");
        return(0);
    }

    else  // If both arguments have been given that are positive numbers, proceed to print out the cylinder's area.
    {
        printf("%.2f\n", area);
        return(0);
    }

    return(0);
}  // End of function.
