// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: is-symmetric.c
Functions: Main, ispalindrome
Parameters: A string
Returns: char
Description: Takes in a string and checks if it's a palindrome.
Author: Patricija Shalkauskaite
*/

// Initialising function.
char ispalindrome(char *array, int length);

int main(int argc, char * argv[])
{   // Start of main function.

    // Defining variables.
    int length = strlen(argv[1]);
    char array[length];


    // Creating array of characters.
    for(int i = 0; i < length; ++i)
    {
        array[i] = argv[1][i];
    }

    ispalindrome(array, length);

    return(0);

}   // End of main function.

char ispalindrome(char *array, int length)
{
    for(int i = 0; i < length; ++i)
    {
        if((array[i] == array[length - 1 - i]) && (i == length - 1)) // If forwards char matches backwards char and loop is finished.
        {
            printf("yes\n");
        }
        else if(array[i] == array[length - 1 - i])  // If for wards char matches backwards char.
        {
            continue;
        }
        else
        {
            printf("no\n");
            break;
        }
    }
}