// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: find-most-character.c
Functions: main, frequent_letter.
Parameters: A string
Returns: int
Description: Takes in a string and checks for the most frequent letter in it.
Author: Patricija Shalkauskaite
*/

// Initialising function.
int frequent_letter(char *sentence);

int main(int argc, char * argv[])
{   // Start of main function.

    frequent_letter(argv[1]);
    return(0);
}

int frequent_letter(char *sentence)
{
    // Defining variables.
    int count = 0;
    int biggest = 0;
    int biggest_index = 0;

    for(int i = 0; i < strlen(sentence); ++i)  // Iterating through each character in sentence.
    {
        for(int j = 0; j < strlen(sentence); ++j)  // Iterating through each character in sentence whilst comparing it to ith character.
        {
            if((sentence[i] == sentence[j]) && sentence[i] != ' ')  // If characters match and ith char isn't a space, increment count.
            {
                count += 1;
            }
        }
        
        if(count > biggest)  // Saving the biggest count of char and its position in the array.
        {
            biggest = count;
            biggest_index = i;
        }

        count = 0;
    }

    printf("%c\n", sentence[biggest_index]);
    
    return(0);
}