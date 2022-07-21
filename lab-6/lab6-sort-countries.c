// Includes.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: sort-countries.c
Functions: main
Parameters: char country, char capital, float population, int size.
Returns: int
Description: Reads country information given, puts them into struct country and prints them out based on their population starting with biggest.
Author: Patricija Shalkauskaite
*/

typedef struct Country Country; //Define Country as a type name

//Structure type definition
struct Country
{
  char country[50];
  char capital[50];
  float population;
  int size;
};

// Function prototype.
void popcheck(Country country[], int count);

int main(int argc, char *argv[])
{
	Country countries[50];  // array of countries with Country struct
  int cc = 0; // country count

  printf("Country\t\t\t");
  printf("Capital\t\t\t");
  printf("Size\t\t\t");
  printf("Population");
  printf("\n");

  for(int i = 1; i < argc - 1; i += 4)  // Building array of struct Country
  {
    strcpy(countries[cc].country, argv[i]);
    strcpy(countries[cc].capital, argv[i + 1]);
    countries[cc].size = atoi(argv[i + 3]);
    countries[cc].population = atof(argv[i+ 2]);
    cc += 1;
  }

  popcheck(countries, cc);
  
  for(int i = 0; i < cc; ++i)
  {
    printf("%s\t\t\t", countries[i].country);
    printf("%s\t\t\t", countries[i].capital);
    printf("%d\t\t\t", countries[i].size);
    printf("%.2f\n", countries[i].population);
  }


  return(0);
}

// Building function prototype.
void popcheck(Country country[], int count)
{
  Country tmp;

  for(int i = 0; i < count; ++i)  // Bubble Sort
  {
    for(int j = 0; j < count; ++j)
    {
      if(country[j + 1].population > country[j].population)  // If next country's population bigger, swap them.
      {
        Country tmp = country[j];
        country[j] = country[j + 1];
        country[j + 1] = tmp;
      }
    }
  }
}