// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: find-country.c
Functions: main
Parameters: char country, char capital, float population, int size.
Returns: struct country
Description: Reads country information given, puts them into struct country and prints them out if their size is less than 100,000km^2.
Author: Patricija Shalkauskaite
*/

typedef struct Country Country; //Define Country as a type name

struct Country //Structure type definition
{
  char country[50];
  char capital[50];
  float population;
  int size;
};

void sizecheck(Country *country);

int main(int argc, char *argv[])
{
	Country country1;  //define a new instance of Player with initialised values
    Country *pcountry1 = NULL;   //Declare the pointer
	pcountry1 = &country1;  //Assign the pointer to the address of country1

    printf("Country\t\t\t");
    printf("Capital\t\t\t");
    printf("Size\t\t\t");
    printf("Population");
    printf("\n");

    for(int i = 1; i < argc - 1; i += 4)
    {
        strcpy(country1.country, argv[i]);
        strcpy(country1.capital, argv[i + 1]);
        country1.size = atoi(argv[i + 3]);
        country1.population = atof(argv[i+ 2]);

        sizecheck(pcountry1);
    }

    return(0);
}

void sizecheck(Country *country)
{
    if(country->size < 100000)
    {
        printf("%s\t\t\t", country->country);
        printf("%s\t\t\t", country->capital);
        printf("%d\t\t\t", country->size);
        printf("%.2f", country->population);
        printf("\n");
    }
}
