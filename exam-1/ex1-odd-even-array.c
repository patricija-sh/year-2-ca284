// Includes.

#include <stdio.h>
#include <stdlib.h>

/*
Name: odd-even-array.c
Functions: Main, sumOdd and minusEven 
Parameters: A list of integers.
Returns: int
Description: Takes in an array of integers and prints the sum of the odd numbers along with the subtraction of even numbers.
Author: Patricija Shalkauskaite
*/

int sumOdd(int *array, int length);
int minusEven(int *array, int length);

int main(int argc, char * argv[])
{
    //Defining variables.
    int length = argc - 1;
    int array[length];

    // Creating array of integers.
    for(int i = 0; i < length; ++i)
    {
        array[i] = atoi(argv[i + 1]);
    }

    printf("%d\n", sumOdd(array, length));
    printf("%d\n", minusEven(array, length));


    return(0);
}

// Building initialised functions.
int sumOdd(int *array, int length)
{   // Start of main function.

    // Defining variables.
    int oddsum = 0;

    for(int i = 0; i < length; ++i)
    {
        if(array[i] % 2 == 1)  // If the element in the array is odd, add it onto oddsum.
        {
            oddsum += array[i];
        } 
    }

    return oddsum;
}  // End of main function.


int minusEven(int *array, int length)
{
    // Defining variables.
    int first_even = 0;
    int first_even_index;

    for(int i = 0; i < length; ++i)
    {
        if(array[i] % 2 == 0)  // If the element in the array is the even number encountered, save it and break the loop.
        {
            first_even = array[i];
            first_even_index = i;
            break;
        }
        else if(i == length)  // If no even element has been found in the array, we print 0. 
        {
            return (0);
        }
    }

    for(int i = 0; i < length; ++i)
    {
        if((array[i] % 2 == 0) && (i != first_even_index))  // Start searching for even elements in array to take away from the first element.
        {
            first_even -= array[i];
        }
    }
    return first_even;
}