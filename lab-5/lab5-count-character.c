// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: count-character.c
Functions: main, count_letter
Parameters: A letter and a sentence.
Returns: int
Description: Takes in a letter and a sentence and counts the amount of the letter given in the sentence.
Author: Patricija Shalkauskaite
*/

// Initialising function.
int count_letter(char letter, char *sentence);

int main(int argc, char * argv[])
{   // Start of main function.
    printf("%d\n", count_letter(*argv[1], argv[2]));
    return(0);
}   // End of main function.

// Building initialised function.
int count_letter(char letter, char *sentence)
{
    char *p_search_letter = sentence;  // Pointer points to first letter of sentence array.
    int count = 0;

    while(p_search_letter = strchr(p_search_letter, letter))  // While NULL is not returned, increment count.
    {
        count += 1;
        p_search_letter += 1;
    }

    return count;
}