// Includes
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Name: calculator.c
Function(s): main, multiply, divide.
Parameters: 1 command and two numbers
Returns: int
Description: Takes in two numbers and based on the command given either multiplies or divides.
Author: Patricija
*/

// Initiate other functions.
float multiply(float a, float b);
float divide(float a, float b);


// Start main function.
int main(int argc, char *argv[])
{
    // Defining variables.
    float a = atof(argv[2]);
    float b = atof(argv[3]);

    if(b != 0)  // As long as you're not diving by zero, proceed.
    {
        if(strcmp(argv[1], "multiply") == 0)  // If command is to multiply, call multiply().
        {
            printf("%f\n", multiply(a, b));
        }
        
        else if(strcmp(argv[1], "divide") == 0) // If command is to divide, call divide().
        {
            printf("%f\n", divide(a, b));
        }
        
        else  // Inappropriate command given.
        {
            printf("invalid\n");
        }
    }

    else  // You are dividing by zero, in which case it's invalid.
    {
        printf("invalid\n");
    }

    return(0);
}  // End of function.

// Building initiated functions.
float multiply(float a, float b)
{
    return a * b;
}

float divide(float a, float b)
{
    return a / b;
}
