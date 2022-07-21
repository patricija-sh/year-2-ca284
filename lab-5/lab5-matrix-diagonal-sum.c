// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: matrix-diagonal-sum.c
Functions: main, sum_diagonally
Parameters: int n and int array of size n.
Returns: int
Description: Takes in a matrix of size n and outputs its diagonal sum.
Author: Patricija Shalkauskaite
*/

// Initialising function.
int sum_diagonally(int *array, int n, int length);

int main(int argc, char * argv[])
{   // Start of main function.

    // Defining variables.
    int n = atoi(argv[1]);
    int length = argc - 2;
    int array[length];

    for(int i = 0; i < length; ++i)  // Creating array.
    {
        array[i] = atoi(argv[i + 2]);
    }

    sum_diagonally(array, n, length);

    return(0);
}   // End of main function.

// Building initialised function.
int sum_diagonally(int *array, int n, int length)
{
    int sum = 0;
    for(int i = 0; i < length;)  // Adding ith element in array to sum.
    {
        sum += array[i];
        i += n + 1;  // This is the pattern to get a matrix's diagonal elements.
    }

    printf("%d\n", sum);
    
    return(0);
}