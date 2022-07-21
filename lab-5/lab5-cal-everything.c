// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*
Name: cal-everything.c
Functions: main, sum, difference, product, division, power, naturalLog.
Parameters: Two integers.
Returns: int.
Description: Takes in two integers and returns their sum, difference, product, division, power and naturalLog.
Author: Patricija Shalkauskaite
*/

// Initialising functions.
float sum(float, float);
float difference(float, float);
float product(float, float);
float division(float, float);
float power(float, float);
float naturalLog(float, float);

int main(int argc, char * argv[])
{   // Start of main function.

    // Defining variables.
    float a = atoi(argv[1]);
    float b = atoi(argv[2]);
    float result = 0;
    float (*pointer_function)(float, float) = NULL;  // A pointer function initialised to NULL.

    pointer_function = sum;
    result = pointer_function(a, b);
    printf("%.2f\n", result);

    pointer_function = difference;
    result = pointer_function(a, b);
    printf("%.2f\n", result);

    pointer_function = product;
    result = pointer_function(a, b);
    printf("%.2f\n", result);

    pointer_function = division;
    result = pointer_function(a, b);
    printf("%.2f\n", result);

    pointer_function = power;
    result = pointer_function(a, b);
    printf("%.2f\n", result);

    pointer_function = naturalLog;
    result = pointer_function(a, b);
    printf("%.2f\n", result);

    return(0);
}   // End of main function.

// Building initialised function.
float sum(float a, float b)
{
    return a + b;
}

float difference(float a, float b)
{
    return a - b;
}

float product(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    return a / b;
}

float power(float a, float b)
{
    return pow(a, b);
}

float naturalLog(float a, float b)
{
    return log(a) + log(b);
}
