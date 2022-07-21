// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: findMax.c
Function(s): main, isbig
Parameters: A list of integers
Returns: int
Description: Takes in a list of numbers and prints out the biggest one.
Author: Patricija
*/

// Initiating functions.
int isbig(int array_element, int comparison);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int array_length = argc - 1;
    int array[100];
    int biggest = 0;
    
    for(int i = 0; i < array_length; ++i)  // Creating an array by converting each command-line argument into an integer.
    {
        array[i] = atoi(argv[i + 1]);
    }

    for(int i = 0; i < array_length; ++i)  // Calling the isbig function to compare which element is bigger.
    {
        biggest = isbig(array[i], biggest);
    }

    printf("%d\n", biggest);

    return(0);
}  // End of main function.

// Building initialised function.
int isbig(int array_element, int comparison)
{
    if(array_element > comparison)  // If element 1 is bigger than element 2, return element 1 and vice versa.
    {
        return array_element;
    }
    else
    {
        return comparison;
    }
}