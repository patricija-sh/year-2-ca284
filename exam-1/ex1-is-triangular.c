// Includes.

#include <stdio.h>
#include <stdlib.h>

/*
Name: is-triangular.c
Functions: Main, isTriangular. 
Parameters: One integer from comman-line.
Returns: int
Description: Takes in an integer and checks if it is a 'triangular number' by performing a quadratic pattern.
Author: Patricija Shalkauskaite
*/

// Initialising function.
int isTriangular(int num);

int main(int argc, char * argv[])
{   // Start of main function.

    // Defining variables.
    int num = atoi(argv[1]);

    isTriangular(num);

    return(0);
}   // End of main function.

int isTriangular(int num)  // isTriangular has a quadratic pattern, so we have first and second difference variables.
{
    int n = 1;
    int first_dif = 2;
    int second_dif = 1;
    while(n <= num)
    {
        if(num == n)
        {
            printf("%d is a triangular number\n", num);
            break;  // If we don't break and input is 1 then it'll be an endless loop.
        }
        else  // If n isn't our input then keep repeating the pattern until we reach it.
        {
            n += first_dif;
            first_dif += second_dif;
        }
    }
    
    if(num != n)
    {
        printf("%d is not a triangular number\n", num);
    }

    return(0);
}