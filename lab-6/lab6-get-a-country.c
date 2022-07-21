// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: get-a-country.c
Functions: main
Parameters: char country, char capital, float population, int size.
Returns: struct country
Description: Reads country information given, puts them into struct country and prints them out.
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

int main(int argc, char*argv[])
{
	Country country1;  //define a new instance of Player with initialised values
	Country *pcountry1 = NULL;   //Declare the pointer
	pcountry1 = &country1;  //Assign the pointer to the address of country1

    strcpy(country1.country, argv[1]);
    strcpy(country1.capital, argv[2]);
    country1.population = atof(argv[3]);
    country1.size = atoi(argv[4]);

    printf("%s\n", pcountry1->country);
    printf("%s\n", pcountry1->capital);
    printf("%.2f million people\n", pcountry1->population);
    printf("%d km2\n", pcountry1->size);

    return(0);
}