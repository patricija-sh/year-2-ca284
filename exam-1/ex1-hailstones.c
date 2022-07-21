// Includes.

#include <stdio.h>
#include <stdlib.h>

/*
Name: hailstones.c
Functions: Main, hailstone.
Parameters: One number.
Returns: int
Description: Takes in a number and prints the hailstone sequence until it hits 1.
Author: Patricija Shalkauskaite
*/


// Initialising hailstone function.
int hailstone(int num);

int main(int argc, char * argv[])
{   // Start of main function.

    // Defining variables.
    int num = atoi(argv[1]);

    hailstone(num);  // Calling the hailstone function.

    return(0);
}

// Building initialised function.
int hailstone(int num)
{
    while(num != 1)  // While the number isn't one, we check if it's even or odd and perform appropriate operations.
    {
        printf("%d ", num);
        if(num % 2 == 0)
        {
            num /= 2;
        }
        else
        {
            num = (num * 3) + 1;
        }
    }

    printf("1\n");

    return(0);
}
