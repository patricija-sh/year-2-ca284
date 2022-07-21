// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: multiple-matrix.c
Functions: main,  multiply_matrices
Parameters: Two matrices.
Returns: int
Description: Takes in two matrices and outputs their product.
Author: Patricija Shalkauskaite
*/

int multiply_matrices(int *matrix1, int *matrix2);

int main(int argc, char * argv[])
{
    int row1 = atoi(argv[1]);
    int column1 = atoi(argv[2]);
    int length1 = row1*column1;
    int matrix1[row1][column1];

    int row2 = atoi(argv[length1 + 3]);
    int column2 = atoi(argv[length1 + 4]);
    int length2 = row2*column2;
    int matrix2[row2][column2];

// MATRIX 1.   
    int j = 0;
    for(int i = 0; i < row1; ++i)  // Making rows.
    {
        while(j < length1)  // Making columns.
        {
            matrix1[i][j] = atoi(argv[j + 3]);
            j += 1;
        }
    }

    // MATRIX 2
    j = 0;
    for(int i = 0; i < row2; ++i)  // Making rows.
    {
        while(j < length2)  // Making columns.
        {
            matrix2[i][j] = atoi(argv[j + length1 + 5]);
            j += 1;
        }
    }


    //multiply_matrices(matrix1, matrix2);

    int new_m[row1][column2];
    int sum = 0;
    int product = 0;

    for(int i = 0; i < row1; ++i)  // Entering the ith row of matrix 1.
    {
        for(int k = 0; k < column2; ++k)  // Entering the kth column of matrix 2.
        {
            sum = 0;
            for(int j = 0; j < column1; ++j) // Entering the jth column of matrix 1, and jth row of matrix 2.
            {
                product = matrix1[i][j] * matrix2[j][k];
                sum += product;
            }
        
        new_m[i][k] = sum;

        if(k + 1 < column2)
        {
            printf("%d ", new_m[i][k]);
        }
        else
        {
            printf("%d", new_m[i][k]);
        }

        }
        
        printf("\n");
    }

    return(0);
}

int multiply_matrices(int *matrix1, int *matrix2)
{

}