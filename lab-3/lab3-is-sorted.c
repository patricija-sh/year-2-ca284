// Includes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
Name: is-sorted.c
Function: Main, 
Parameters: 
Returns: int
Description: 
Author: Patricija
*/

void bubble_sort(int array[], int length);


int main(int argc, char *argv[])
{
    int length = argc - 1;
    int array[length];

    // Adding command line arguments into an array.
    for(int i = 0; i < length; ++i)
    {
        array[i] = atoi(argv[i + 1]);
    }
    
    // for(int i = 0; i < length; ++i)
    // {
    //     printf("Original: %d\n", array[i]);
    // }

    bubble_sort(array, length);

    for(int i = 0; i < length; ++i)
    {
        printf("%d\n", array[i]);
    }

    return(0);
}

void bubble_sort(int array[], int length)
{
    for(int i = 0; i < length; ++i)
    {
        for(int j = i + 1; j < length; ++j)
        {
            if(array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp; 
            }
        }
    }
}