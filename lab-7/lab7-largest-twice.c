// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: second-largest.c
Functions: main, findHalfBiggest
Parameters: list of ints
Returns: int
Description: Reads in a list of int and outputs their largest element if an element half of or less than the biggest element exists.
Author: Patricija Shalkauskaite
*/

// Initialising function.
void findHalfBiggest(int *numlist, int listsize);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables
    int size = argc - 1;
    int *numlist = malloc(size*sizeof(int));  // Allocate sufficient space for the array of numbers.

    for(int i = 0; i < size; ++i)  // Creating float list.
    {
        numlist[i] = atoi(argv[i + 1]);  // It's + 1 to exclude the program name.
    }

    findHalfBiggest(numlist, size);
    free(numlist);  // Free up the numlist storage.

    return(0);
}

// Building initialised function.
void findHalfBiggest(int *numlist, int listsize)
{
    int biggest = 0;

    for(int i = 0; i < listsize; ++i)  // Searching for the biggest elememt.
    {
        if(numlist[i] > biggest)
        {
            biggest = numlist[i];
        }
    }

    for(int i = 0; i < listsize; ++i)  // Searching for element that's half or less than the biggest element.
    {
        if(numlist[i] <= biggest / 2)
        {
            printf("%d\n", biggest);
            break;
        }
        else if(i == listsize - 1)
        {
            printf("0\n");
        }
    }
}