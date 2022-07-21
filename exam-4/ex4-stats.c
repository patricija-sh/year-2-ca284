// Import libraries.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Name: ex4-stats.c
Functions: main, check_command, find_max, find_mode, find_std_dev
Parameters: array of numbers, with the final number representing a command (char *argv[]).
Returns: int answer based on command given.
Description: Function takes in an array of numbers and based on the last number (representing a command) it calls the appropriate
             function and outputs the answer.
Author: Patricija Shalkauskaite
Date: 09-12-2021
*/

// Function prototoypes.
void check_command(int command, int nums[], int length);  // Check which command is specified.
float find_max(int nums[], int length);  // Find the biggest element in the integer array.
float find_mode(int nums[], int length);  // Find the most frequent element in the integer array.
float find_std_dev(int nums[], int length);  // Find the standard deviation of the integer array.

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int command = atoi(argv[argc - 1]);  // The command we'll use to decide what function to use.
    int length = argc - 2;  // We're not including the command or program name.
    int nums[length];

    for(int i = 0; i < length; ++i)  // Create integer array.
    {
        nums[i] = atoi(argv[i + 1]);  // + 1 to exclude the program name.
    }

    check_command(command, nums, length);

    return 0;
}

/*
    Function Name: check_command
    Parameters: a command (int command), an integer array (int nums[]) and the array's length (int length).
    Description: Based on the command given, initialise a pointer function and call the function through that.
                 The result will be returned the the result variable and the answer will be printed.
*/

void check_command(int command, int nums[], int length)
{
    float (*pfunction)(int*, int);
    float result = 0;

    switch(command)
    {
        case 1:
            pfunction = find_max;
            result = pfunction(nums, length);
            printf("%.0f\n", result);
            break;
        
        case 2:
            pfunction = find_mode;
            result = pfunction(nums, length);
            printf("%.0f\n", result);
            break;
        
        case 3:
            pfunction = find_std_dev;
            result = pfunction(nums, length);
            printf("%.2f\n", result);
            break;

        default:
            pfunction = find_max;
            result = pfunction(nums, length);
            printf("%.0f\n", result);
            break;
    }
}

/*
    Function Name: find_max
    Parameters: an integer array (int nums[]) and the array's length (int length).
    Description: Gets the biggest integer in the array by comparing the biggest element seen so far to the next.
*/

float find_max(int nums[], int length)
{
    int biggest = nums[0];
    for(int i = 1; i < length; ++i)
    {
        if(nums[i] > biggest)
        {
            biggest = nums[i];
        }
    }

    return biggest;
}

/*
    Function Name: find_mode
    Parameters: an integer array (int nums[]) and the array's length (int length).
    Description: Gets the most frequent element by using two for loops and incrementing count for every time element j is seen.
*/

float find_mode(int nums[], int length)
{
    int most_frequent_count = 0;
    int most_frequent_num = 0;
    int frequency_count = 0;

    for(int i = 0; i < length; ++i)
    {
        frequency_count = 0;
        for(int j = 0; j < length; ++j)
        {
            if(nums[i] == nums[j])
            {
                frequency_count += 1;
            }
        }
        
        if(frequency_count > most_frequent_count)
        {
            most_frequent_count = frequency_count;
            most_frequent_num = nums[i];
        }
    }

    return most_frequent_num;
}

/*
    Function Name: find_std_dev
    Parameters: an integer array (int nums[]) and the array's length (int length).
    Description: Finds the standard deviation 
*/

float find_std_dev(int nums[], int length)
{
    float sum = 0.0;
    float mean = 0.0;
    float squared_deviance = 0.0;

    for (int i = 0; i < length; ++i)  // Step 1. Get the sum of all numbers.
    {
        sum += nums[i];
    }
    
    mean = sum / length;  // Step 2. Get the mean.
    
    for (int i = 0; i < length; ++i)  // Step 3. get the sum of the squared deviance.
    {
        squared_deviance += pow(nums[i] - mean, 2);
    }
    
    return sqrt(squared_deviance / length);  // Step 4. Divide it by the total amount of elements and get the square root of that.
}