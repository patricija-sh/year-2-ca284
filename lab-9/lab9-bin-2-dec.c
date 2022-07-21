// Import libraries.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/*
Name: bin-2-dec.c
Functions: main, bin_to_dec
Parameters: up to 8 ints.
Returns: int
Description: Reads in a binary number, converts it in void function and prints the decimal format in main.
Author: Patricija Shalkauskaite
Date: 19-11-2021
*/

void bin_to_dec(int *dec_num, int bin_num, int index);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int length = argc - 1;
    int decimal_num = 0;

    if(length <= 8)  // Program does not accept more than 8 binary digits.
    {
        for(int i = 0; i < length; ++i)  // We'll pass each individual binary digit to the void function.
        {
            if(strcmp(argv[argc - 1 - i], "1") == 0 || strcmp(argv[argc - 1 - i], "0") == 0)  // Using atoi() will return 0.
            {
                bin_to_dec(&decimal_num, atoi(argv[argc - 1 - i]), i);
            }
            else  // It's not a binary number.
            {
                printf("Only digits 1 and 0 are permitted.\n");
                return(0);
            }
        }
    }
    else
    {
        printf("Too many binary digits entered.\n");
        return(0);
    }

    printf("%d\n", decimal_num);

    return(0);
}   // End of main function.

// Building initialised function.
void bin_to_dec(int *dec_num, int bin_num, int index)
{
    // Defining variables.
    int power_of = 0;

    power_of = pow(2, index);
    *dec_num += bin_num * (power_of);
}