// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: second-largest.c
Functions: main, secondBiggest
Parameters: list of floats.
Returns: float
Description: Reads in a list of floats and outputs their second largest element.
Author: Patricija Shalkauskaite
*/

// Initialising function.
void secondBiggest(float *floatlist, int listsize);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int listsize = argc - 1;
    float *floatlist = malloc(listsize*sizeof(float));  // Assigning suitable space for the float list.

    for(int i = 0; i < listsize; ++i)  // Creating float list.
    {
        floatlist[i] = atof(argv[i + 1]);
    }

    secondBiggest(floatlist, listsize);

    free(floatlist);  // Frees up floatlist.

    return(0);
}   // End of main function.

// Building initialised function.
void secondBiggest(float *floatlist, int listsize)
{   // Defining variables.
    float biggest = floatlist[2];
    float secondbiggest = floatlist[2];

    for(int i = 0; i < listsize; ++i)  // Finding largest.
    {
        if(floatlist[i] > biggest)
        {
            biggest = floatlist[i];
        }
    }

    for(int i = 0; i < listsize; ++i)  // Finding second largest.
    {
        if((floatlist[i] > secondbiggest) && (floatlist[i] != biggest))
        {
            secondbiggest = floatlist[i];
        }
    }

    printf("%.1f\n", secondbiggest);
}