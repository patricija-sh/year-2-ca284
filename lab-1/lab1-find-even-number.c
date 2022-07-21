/*
    Program: find-even-number.c
    Author: Patricija
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

/*  Function: Main
    Parameters: int argc (argument count), char *argv[] an array of command-line arguments.
    Description:  Takes a maximum of 10 numbers and prints the even number and its index in the array.
*/

int main(int argc, char *argv[])
{   // Start of function.


    //Initialising variables.
    int arraylength = argc - 1; // The first argc is always program name so the length needs to be the length of commands excluding the program name.
    int numberlist[arraylength];
    int evencounter = 0;

    for(int i = 0; i < arraylength; ++i)
    {
        numberlist[i] = atoi(argv[i + 1]); // Because argv[0] is just the program name so it has to be i + 1.
    }

    for(int i = 0; i < arraylength; ++i)
    {
        if(numberlist[i] % 2 == 0) // A number modulus (%) 2 will give 0 when even and 1 when odd.
        {
            evencounter += 1;
            printf("%d - %d\n", i, numberlist[i]);
        }
    }

    if(evencounter == 0)
    {
        printf("Not found!\n");
    }
 
    return(0);

} // End of function.