// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: ex4-duplicate-remover.c
Functions: main, avoid_duplicates
Parameters: array of ints.
Returns: int
Description: Reads in an array of integers, puts them all into an array, then it finds any duplicates and omits them as well as the
             numbers themselves when printing them out.
Author: Patricija Shalkauskaite
Date: 09-12-2021
*/

// Function prototypes.
void avoid_duplicates(int *nums, int length);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int length = argc - 1;
    int *pnums = calloc(length, sizeof(int));
    if(!pnums)
    {
        printf("Memory allocation has failed.\n");
        free(pnums);
        pnums = NULL;
        exit(0);
    }

    for(int i = 0; i < length; ++i)
    {
        *(pnums + i) = atoi(argv[i + 1]);
    }
    avoid_duplicates(pnums, length);

    free(pnums);

    return 0;
}   // End of main function.

/*
    Function Name: avoid_duplicates
    Parameters: int *nums, int length
    Description: Checks for duplicates and omits them including the number itself when printing.
                 This is done by having a count for each number and if it's above 1 then it's a duplicate so it's not printed.
*/

void avoid_duplicates(int *nums, int length)
{
    int count = 0;

    for(int i = 0; i < length; ++i)
    {
        count = 0;
        for(int j = 0; j < length; ++j)
        {
            if(nums[i] == nums[j])
            {
                count += 1;
            }
        }
        if(count == 1)
        {
            printf("%d\n", nums[i]);
        }
    }
}

