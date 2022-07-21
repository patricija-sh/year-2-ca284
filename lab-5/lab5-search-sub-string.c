// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: search-sub-string.c
Functions: main, substring_check
Parameters: sentence, word
Returns: int
Description: Takes in a string and a word and checks if the word is contained in the string.
Author: Patricija Shalkauskaite
*/

// Initialising function.
int substring_check(char *sentence, char *word);

int main(int argc, char * argv[])
{   // Start of main function.

    substring_check(argv[1], argv[2]);

    return(0);
}   // End of main functin

// Building initialised function.
int substring_check(char *sentence, char *word)
{
    // Defining variables.
    int start_index = 0;
    int end_index = 0;
    int j = 0;

    if(strstr(sentence, word))  // If the word is a substring of the sentence.
    {
        for(int i = 0; i < strlen(sentence); ++i)  // Iterate through the sentence.
        {
            if(strncmp(word, &sentence[i], strlen(word)) == 0)  // If word matches ith iteration of sentence up as far as len(word).
            {
                start_index = i;
                end_index = i + (strlen(word) - 1);
            }
        }
    }

    printf("%d %d\n", start_index, end_index);

    return(0);
}