// Import libraries.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Name: product.c
Functions: main, add_nodes, find_ireland, update_price, print_nodes.
Parameters: product code (char), origin country (char), price (int).
Returns: struct Node

Description: Reads in an array of products, puts them all into a linked list, then it finds which product has the origin_code "Ireland",
             and updates the product's price, increasing it by 20%.
             The function outputs all products given and their info, with the updated prices.

Author: Patricija Shalkauskaite
Date: 25-11-2021
*/

// Defining structure type Node.
typedef struct Node Node;
typedef struct Product Product;

struct Node  // A modified doubly linked list with extra properties.
{
    char product_code[50];
    char origin_country[50];
    unsigned int price;
    Node *next;
    Node *prev;
};

// Function prototypes;
Node *add_nodes(char *argv[], int length);  // Adds nodes to linked list.
Node *find_ireland(Node *start);  // Checks each product to find which one is from Ireland.
int update_price(Node *irish_product);  // Updates irish products' prices, increasing it up by 20%.
void print_nodes(Node *start);  // Prints out all products inputted and their information.

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    Node *start = NULL;
    int length = argc - 1;
    int product_amount = length / 3;  // Divide by three because each product has 3 properties to it.

    start = add_nodes(argv, length);
    start = find_ireland(start);

    print_nodes(start);

    return(0);
}

Node *add_nodes(char *argv[], int length)
{
    Node *current, *first, *prev;  // Declaring three pointers.

    first = (Node*)calloc(1, sizeof(Node));  // Creating the first node.
    
    current = first;                         // Current pointer points to the first node now.
    strcpy(current->product_code, argv[1]);      // Input data for first node.
    strcpy(current->origin_country, argv[2]);
    current->price = atoi(argv[3]);

    for(int i = 3; i < length - 1; i += 3)  // Putting the rest of the values in the linked list.
    {
        current->next = (Node*)calloc(1, sizeof(Node));
        prev = current;
        current = current->next;
        strcpy(current->product_code, argv[i + 1]);      // Input data for first node.
        strcpy(current->origin_country, argv[i + 2]);
        current->price = atoi(argv[i + 3]);
        current->prev = prev;
    }

    current->next = NULL;
    return first;
}

Node *find_ireland(Node *start)
{
    Node* p = NULL;

    for(p = start; p != NULL; p = p->next)
    {
        if(strcmp(p->origin_country, "Ireland") == 0)  // Check to see if this is an irish product.
        {
            p->price = update_price(p);
        }
    }

    return start;
}

int update_price(Node *irish_product)
{
    Node* p = irish_product;

    p->price += p->price * 0.2;  // Increasing price by 20%.

    return p->price;
}


void print_nodes(Node *start)
{
    Node* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%s\n", p->product_code);
        printf("%s\n", p->origin_country);
        printf("%d\n", p->price);
    }
}
