// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: average-popualtion.c
Functions: main
Parameters: char country, char capital, float population, int size.
Returns: int
Description: Reads country information given, puts them into struct country and prints them out along with their average population.
Author: Patricija Shalkauskaite
*/

// Initialising function
float get_average(float sum, int j);

typedef struct Country Country; //Define Country as a type name


struct Country //Structure type definition
{
  char country[50];
  char capital[50];
  float population;
  int size;
};

int main(int argc, char*argv[])
{   // Start of main function

    // Defining variables
    Country country1;  //define a new instance of Player with initialised values
	Country *pcountry1 = NULL;   //Declare the pointer
	pcountry1 = &country1;  //Assign the pointer to the address of country1
    float sum = 0;
    int j = 0;

    printf("Country\t\t\t");
    printf("Capital\t\t\t");
    printf("Size\t\t\t");
    printf("Population");
    printf("\n");

    for(int i = 1; i < argc - 1; i += 4)
    {
        strcpy(country1.country, argv[i]);
        printf("%s\t\t\t", pcountry1->country);

        strcpy(country1.capital, argv[i + 1]);
        printf("%s\t\t\t", pcountry1->capital);

        country1.size = atoi(argv[i + 3]);
        printf("%d\t\t\t", pcountry1->size);

        country1.population = atof(argv[i+ 2]);
        printf("%.2f", pcountry1->population);

        sum += pcountry1->population;

        printf("\n");

        j += 1;  // his gives us the number of countries inputted
    }

    get_average(sum, j);

    return(0);
}

// Building initialised function
float get_average(float sum, int j)
{
    printf("Population average: %.2f\n", sum/j);  // Getting average of population.
}