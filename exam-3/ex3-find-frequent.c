// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: find-frequent.c
Functions: main, add_nums, bubble_sort, get_count, is_frequent, print_frequent.
Parameters: array of ints.
Returns: int
Description: Reads in an array of integers, puts them in a list, then sorts them in ascending order.
             Finally, if the number count is > 3, the number will be printed as many times as is their count.
Author: Patricija Shalkauskaite
Date: 25-11-2021
*/

// Function prototypes.
void bubble_sort(int *p_nums, int length);  // Sorting the integer array will make it easier to print out the frequent nums in ascending order.
void get_count(int *num_pointer, int length);  // Loop through the list and compare the numbers to check if they're the same and increment their count.
void is_frequent(int num, int count);  // get_count will call is_frequent to check if the count is more than 3 and then print out the elements.
void print_frequent(int num, int count);
 
 
int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int capacity = 5;  // Initial size of p_nums will be 5.
    int length = argc - 1;
    int *p_nums = calloc(capacity, sizeof(int));
    if(!p_nums)
    {
        //Do something if failed to allocate memory, e.g.:
        printf("Not enough memory!");
        exit(0);
    }
 
    for(int i = 0; i < length; ++i)
    {
        p_nums[i] = atoi(argv[i + 1]);

        if(i == capacity - 1)  // If we have exceeded the max capacity set, reallocate memory.
        {
            int *p_temp;
            capacity += 1;
            p_temp = (int*)realloc(p_nums, capacity * sizeof(int));
            if(!p_temp)  // Check if the re-allocation is successful.
            {
                printf("Unfortunately memory reallocation failed. Exiting...\n");
                free(p_nums);
                p_nums = NULL;
                exit(0);
            }
             
            p_nums = p_temp;
        }
    }
     
    bubble_sort(p_nums, length);  // Sort the numbers in ascending order.
    get_count(p_nums, length);
 
    return(0);
}   // End of main function.
 
// Building prototypes.
void bubble_sort(int *p_nums, int length)
{
    for(int i = 0; i < length; ++i)
    {
        for(int j = i + 1; j < length; ++j)  // This way, if i = 0, then j = 1 etc.
        {
            if(p_nums[i] > p_nums[j])  // If the element on the left is bigger than the right, swap them.
            {
                int temp = p_nums[i];
 
                p_nums[i] = p_nums[j];
                p_nums[j] = temp; 
            }
        }
    }
}
 
void get_count(int *num_pointer, int length)
{
    int count = 0;
 
    for(int i = 0; i < length; ++i)
    {
        count = 0;
        for(int j = 0; j < length; ++j)
        {
            if(num_pointer[i] == num_pointer[j])  // Compare elements to one another.
            {
                count += 1;
            }
        }
 
        is_frequent((num_pointer[i]), count);
    }
}
 
void is_frequent(int num, int count)
{
    if(count > 3)
    {
        print_frequent(num, count);
    }
}
 
void print_frequent(int num, int count)
{
    printf("%d\n", num);
}