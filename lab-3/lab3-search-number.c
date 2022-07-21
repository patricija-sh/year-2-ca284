// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: search-number.c
Function(s): main, find_element
Parameters: A list of integers
Returns: int
Description: Takes in an element to be found as well as a list of integers to be searched through.
Author: Patricija
*/

// Initialising function.
int find_element(int to_find, int array_element);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int length = argc - 2;  // It's - 2 because we don't want the to_find item included in the list of elements to be searched.
    int array[length];
    int to_find = atoi(argv[1]);  // Convert item to be found into an integer.

    for(int i = 0; i < length; ++i)  // Creating an array of integers.
    {
        array[i] = atoi(argv[i + 2]);
    }

    for(int i = 0; i < length; ++i)
    {
        if(find_element(to_find, array[i]) == 0)  // If we have found the item in our array, say so.
        {
            printf("Found %d at %d\n", to_find, i);
            break;
        }
        else if(i == length)  // Else declare we have not found the element.
        {
            printf("%d not found\n", to_find);
            break;
        }
    }
}  // End of main function.


// Building initialised function.
int find_element(int to_find, int array_element)
{
    if(to_find == array_element)  // If we have successfully found the item in our array.
    {
        return 0;
    }
}