// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: largest-smallest.c
Functions: Main, smallest, largest.
Parameters: One command followed by sequence of floats.
Returns: int
Description: Takes in a command and array of floats and prints either largest or smallest depending on command given.
Author: Patricija Shalkauskaite
*/

float smallest(float *array, int length);
float largest(float *array, int length);

int main(int argc, char * argv[])
{   // Start of main function.

    // Defining variables.
    int length = argc - 2;  // It's -2 because we don't want to include the program call and command.
    float array[length];

    for( int i = 0; i < length; ++i)
    {
        array[i] = atof(argv[i + 2]);
    }

    if(strcmp(argv[1], "smallest") == 0)
    {
        printf("%.2f\n", smallest(array, length));
    }
    
    else if(strcmp(argv[1], "largest") == 0)
    {
        printf("%.2f\n", largest(array, length));
    }

    return(0);
}  // End of main function.


// Building initialised functions.
float smallest(float *array, int length)
{
    // Defining variables.
    float smallest = array[1];

    for(int i = 0; i < length; ++i)  // Comparing elements to find the smallest one.
    {
        if(array[i] < smallest)
        {
            smallest = array[i];
        }
    }

    return smallest;
}

float largest(float *array, int length)
{
    // Defining variables
    float biggest = 0;

    for(int i = 0 ; i < length; ++i)  // Comparing elements to find the largest one.
    {
        if(array[i] > biggest)
        {
            biggest = array[i];
        }
    }

    return biggest;
}