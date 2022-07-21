// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: dot-product-two-vector.c
Functions: main, dotProduct
Parameters: Vector size int n, followed by first n integers of vector 1 and last n elements of vector 2.
Returns: int
Description: Reads vector size n followed by elements of vector 1 and 2 and outputs their dot product.
Author: Patricija Shalkauskaite
*/

// Initalising functions.
void dotProduct(int *vector1, int *vector2, int vector_size);

int main (int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    int vector_size = atoi(argv[1]);
    int *vector1 = (int*)malloc(vector_size * sizeof(int));  // Initalise a pointer to vector1 with sufficient space for int.    
    int *vector2 = (int*)malloc(vector_size * sizeof(int));
    int j = 0;  // Save the index of when first vector creation is complete.
    
    // Checking if the vectors have space.
    if(!vector1)
    {
        printf("Not enough memory.");
        exit(0);
    }

    if(!vector2)
    {
        printf("Not enough memory.");
        exit(0);
    }

    for(int i = 0; i < vector_size; ++i)  // Vector 1 creation.
    {
        vector1[i] = atoi(argv[i + 2]); // It's i + 2 because we don't wish to include program name or first input (that's vector_size).
        j += 1;
    }

    for(int i = 0; i < vector_size; ++i)  // Vector 2 creation.
    {
        vector2[i] = atoi(argv[j + 2]);
        j += 1;
    }

    dotProduct(vector1, vector2, vector_size);
    
    // Free both vectors.
    free(vector1);
    free(vector2);

    return(0);
}   // Enf of main function.

// Builsing initialised function.
void dotProduct(int *vector1, int *vector2, int vector_size)
{
    int dotproduct = 0;

    for(int i = 0; i < vector_size; ++i)
    {
        dotproduct += vector1[i]*vector2[i];
    }

    printf("%d\n", dotproduct);

}