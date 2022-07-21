// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: longest-sentence.c
Functions: main, longestString, findCountandString
Parameters: list of str
Returns: int
Description: Reads in a list of str and outputs the longest string(s)
Author: Patricija Shalkauskaite
*/

int longestString(char **stringlist, int length);
void findCountandString(char **stringlist, int length, int longest);

int main(int argc, char *argv[])
{
    int length = argc - 1;
    char **stringlist = malloc(length*sizeof(char*));  // An array of char pointers.
    if(!stringlist)
    {
        printf("Not enough memory.");
        free(stringlist);
        exit(0);
    }

    for(int i = 0; i < length; ++i)  // For each pointer, sufficient memory is assigned.
    {
        stringlist[i] = malloc(strlen(argv[i + 1]) * sizeof(char));
        stringlist[i] = argv[i + 1];
    }

    // for(int i = 0; i < length; ++i)
    // {
    //     printf("%s\n", stringlist[i]);
    // }

    int longest = longestString(stringlist, length);
    findCountandString(stringlist, length, longest);

    free(stringlist);

    return(0);
}

int longestString(char **stringlist, int length)
{
    int longest = strlen(stringlist[1]);
    int count = 0;

    for(int i = 0; i < length; ++i)
    {
        if(strlen(stringlist[i]) >= longest)
        {
            longest = strlen(stringlist[i]);
        }
    }
    return longest;

}

void findCountandString(char **stringlist, int length, int longest)
{
    int count = 0;

    for(int i = 0; i < length; ++i)
    {
        if(strlen(stringlist[i]) == longest)
        {
    	    count += 1;
        }
    }

    // We now know how many longest items we have.
    char **longest_string_list = malloc(count*sizeof(char*));  // An array of char pointers.

    for(int i = 0; i < length; ++i)  // For each pointer, sufficient memory is assigned.
    {
        if(strlen(stringlist[i]) == longest)
        {
            longest_string_list[i] = malloc(strlen(stringlist[i]) * sizeof(char));
            longest_string_list[i] = stringlist[i];
            printf("%s\n", longest_string_list[i]);
        }
    }
}