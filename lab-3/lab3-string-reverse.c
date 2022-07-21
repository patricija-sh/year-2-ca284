// Includes.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Name: string-reverse.c
Function(s): main, reverse.
Parameters: A sentence as one command-line argument. 
Returns: char
Description: Takes in a string and prints out its reverse.
Author: Patricija
*/

// Initiate other functions.
char reverse(char *input);  // The * acts as a pointer to the command-line argument we give the reverse function.

int main(int argc, char *argv[])
{  // Start main function.

    // Calling reverse function.
    reverse(argv[1]);

    return(0);
}  // End of function.

// Building initialised function.
char reverse(char *input)
{
    // Defining variables.
    int length = strlen(input);

    for(int i = length - 1; i >= 0; --i)
    {
        printf("%c", input[i]);  // Printing the input given backwards.
    }
    printf("\n");
}