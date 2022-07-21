// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Name: duplicated-numbers.c
Function: Main, find_dupe
Parameters: an array of integers
Returns: int
Description: Takes in an array and prints out first duplicate if any exist.
Author: Patricija
*/


// Initiating function.
int find_dupe(int first_element, int second_element, int first_loop, int second_loop);


int main(int argc, char *argv[])
{   // Start of function.

    // Defining variables.
    int length = argc - 1;
    int array[length];
    int found_dupe = 0;
    int duplicate;

    // Adding command line arguments into an array.
    for(int i = 0; i < length; ++i)
    {
        array[i] = atoi(argv[i + 1]);
    }

    // Loop goes through each item in list and calls function to check if they're the same.
    for(int i = 0; i < length; ++i)
    {
        for(int j = i; j < length; ++j)
        {
            duplicate = find_dupe(array[i], array[j], i, j);
            
            if(duplicate != -1)  // If we have found a duplicate, say so and break the inner loop.
            {
                printf("%d\n", duplicate);
                break;
            }
        }
        
        if(duplicate != -1)  // If we have found the element, break the outer loop.
        {
            break;
        }

        else if(i == length - 1)  // If we're at the end of the list and we haven't found a duplicate, say so.
        {
            printf("no duplicated number\n");
        }
    }

    return(0);
}   // Function end.


// Building initialised function.
int find_dupe(int first_element, int second_element, int first_loop, int second_loop)
{
    if((first_element == second_element) && (first_loop != second_loop))
    {
        int found_dupe = 1;
        return second_element;
    }
    else  // Because our array of integers are only positive numbers, this negative number will indicate failure.
    {
        return -1;
    }
}