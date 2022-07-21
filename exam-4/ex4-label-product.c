// Import libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: ex4-label-product.c
Functions: main, add_nodes, get_average_sales, find_above_average, update_status, print_nodes.
Parameters: array of strings representing products and their information (char *argv[]).
Returns: Cart
Description: Takes in product and their information such as item code, price and amount sold.
             They are added to the Cart linked list structure.
             The average sales is calculated and each product's sales is compared to that.
             If the product's sales are above average, then their status becomes 1.
             Finally the full name of the origin country and their status is printed.
Author: Patricija Shalkauskaite
Date: 09-12-2021
*/

typedef struct Cart Cart; // Define Cart as a type name.

struct Cart //Structure type definition.
{
  char item_code[20];
  float price;
  unsigned int amount_sold;
  int status;  // 0 if product's sales are below the average sales, 1 otherwise.
  Cart *next;
  Cart *prev;
};

// Function prototypes;
Cart *add_nodes(char *argv[], int length);  // Adds nodes to linked list.
float get_average_sales(Cart *start, int product_amount);  // Find the products' average sales/
Cart *find_above_average(Cart *start, float average_sales);  // Compare each product to the average sales.
int update_status(Cart *item);  // Updates items' status' to 1 if their sales is above the average sales.
void print_nodes(Cart *start);  // Prints out all products inputted and their information.

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    Cart *start = NULL;
    int length = argc - 1;
    int product_amount = length / 3;  // Divide by three because each product has 3 properties to it.
    float average_sales;

    start = add_nodes(argv, length);

    average_sales = get_average_sales(start, product_amount);

    find_above_average(start, average_sales);
    print_nodes(start);

    free(start);
    start = NULL;

    free(start);

    return 0;
}   // End of main function.


/*
    Function Name: add_nodes
    Parameters: char *argv[], int length
    Description: Puts the products into a linked list.
*/

Cart *add_nodes(char *argv[], int length)
{
    // Defining variables.
    Cart *current, *first, *prev;  // Declaring three pointers.

    first = (Cart*)calloc(1, sizeof(Cart));  // Creating the first node.
    
    current = first;                         // Current pointer points to the first node now.
    strcpy(current->item_code, argv[1]);      // Input data for first node.
    current->price = atof(argv[2]);
    current->amount_sold = atoi(argv[3]);
    current->status = 0;

    for(int i = 3; i < length - 1; i += 3)  // Putting the rest of the values in the linked list.
    {
        current->next = (Cart*)calloc(1, sizeof(Cart));
        prev = current;
        current = current->next;
        strcpy(current->item_code, argv[i + 1]);      // Input data for first node.
        current->price = atof(argv[i + 2]);
        current->amount_sold = atoi(argv[i + 3]);
        current->status = 0;
        current->prev = prev;
    }

    current->next = NULL;
    return first;
}

/*
    Function Name: get_average_sales
    Parameters: a Cart linked list (Cart *start) and the total amount of products (int product_amount).
    Description: Iterates through the Cart linked list and finds the average sales of the products in the linked list.
*/

float get_average_sales(Cart *start, int product_amount)
{
    // Defining variables.
    float sales = 0.0;
    
    Cart *p = NULL;

    for(p = start; p != NULL; p = p->next)
    {
        sales += p->price * p->amount_sold;
    }

    return sales / product_amount;
}

/*
    Function Name: get_average_sales
    Parameters: Cart *start, int product_amount
    Description: Iterates through the Cart linked list and compares the current product's sales with the average sales and updates
                 their status accordingly.
*/

Cart *find_above_average(Cart *start, float average_sales)
{
    Cart *p = NULL;
    float sales = 0.0;

    for(p = start; p != NULL; p = p->next)
    {
        sales = p->price * p->amount_sold;  // Calculation of sale
        if(sales >= average_sales)
        {
            p->status = update_status(p);
        }
    }

    return start;
}

/*
    Function Name: update_status
    Parameters: Cart *item
    Description: Ifthe product's sales are above average, change its status to 1.
*/

int update_status(Cart *item)
{
    Cart *p = item;

    p->status = 1;  // The product's sales are >= to average sales.

    return p->status;
}

void print_nodes(Cart *start)
{
    Cart *p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        if(strncmp(p->item_code, "IE", 2) == 0)
        {
            printf("%d\n", p->status);
            printf("Ireland\n");
        }
        else if(strncmp(p->item_code, "FR", 2) == 0)
        {
            printf("%d\n", p->status);
            printf("France\n");
        }
        else if(strncmp(p->item_code, "SP", 2) == 0)
        {
            printf("%d\n", p->status);
            printf("Spain\n");
        }
        else if(strncmp(p->item_code, "US", 2) == 0)
        {
            printf("%d\n", p->status);
            printf("USA\n");
        }
        else if(strncmp(p->item_code, "RU", 2) == 0)
        {
            printf("%d\n", p->status);
            printf("Russia\n");
        }
    }
}