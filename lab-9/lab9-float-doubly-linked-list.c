// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: receipt.c
Functions: main, add_cart, check_item_sale, get_promo_price, print_total.
Parameters: Multiple char array, int, float, int.
Returns: struct and str.
Description: Reads in an array of grocery items and outputs the total price of all groceries, promotional price included.
Author: Patricija Shalkauskaite
Date: 11-11-2021
*/

typedef struct Node Node;

struct Node
{
    float value;
    Node *next;
    Node *prev;
};

// Initialising function(s).
Node* get_nodes(char *argv[]);
void print_nodes_reversed(Node *last);

int main(int argc, char *argv[])
{
    Node *start = NULL;

    start = get_nodes(argv);
    print_nodes_reversed(start);

    return(0);
}

Node* get_nodes(char *argv[])
{
    Node *current, *first, *prev;  // Decalring three pointers.
    int length = atoi(argv[1]) - 1;
    first = (Node*)calloc(1, sizeof(Node));  // Creating the first node.
    current = first;  // Current pointer points to the first node now.
    
    // Input data for first node.
    current->value = atoi(argv[2]);

    for(int i = 0; i < length; ++i)
    {
        current->next = (Node*)calloc(1, sizeof(Node));
        prev = current;
        current = current->next;
        current->value = atoi(argv[i + 3]);
        current->prev = prev;
    }

    current->next = NULL;
    return current;
}

void print_nodes_reversed(Node *last)
{
    Node* p = NULL;
    for(p = last; p != NULL; p = p->prev)
    {
        printf("%.2f\n", p->value);
    }
}
