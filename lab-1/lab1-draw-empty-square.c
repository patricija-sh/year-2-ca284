/*
    Program: draw-empty-square.c
    Author: Patricija
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

/*  Function: Main
    Parameters: int argc (argument count), char *argv[] an array of command-line arguments.
    Description:  Takes in 1 argument, the length (and width) of a square and prints out an empty square.
*/

int main(int argc, char *argv[1])
{   // Start of function

    // Initialising variables
    int length = atoi(argv[1]);

    for(int i = 0; i < length; ++i)
    {
        if(i == 0 || i + 1 == length)  // Checking if we're on the first or last line to print out the top and bottom of the square.
        {
            for(int j = 0; j < length; j++)
            {
                printf("*");
            }
        }
        else  // Else we print out the inner remaining part of the square.
        {
            for(int j = 0; j < length; j++)
            {
                if(j == 0 || j + 1 == length)  // Checking if we print out the side borders of the square or not.
                {
                    printf("*");
                } else
                {
                    printf(" ");
                }
            }
       }
       printf("\n");
    }
    return(0);
}  // End of function.