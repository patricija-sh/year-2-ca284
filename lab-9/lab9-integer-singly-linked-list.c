// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: integer-singly-linked-list.c
Functions: main, add_nodes, print_nodes.
Parameters: array of ints.
Returns: Nodes
Description: Reads in an array integers and puts them into a linked list and prints them out.
Author: Patricija Shalkauskaite
Date: 19-11-2021
*/

// Defining structure type Node.
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
};

// Initialising function(s).
Node* add_nodes(char *argv[]);
void print_nodes(Node *start);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    Node *start = NULL;

    start = add_nodes(argv);
    print_nodes(start);

    return(0);
}

Node* add_nodes(char *argv[])
{
    Node *current, *first;                   // Declaring two pointers.
    int length = atoi(argv[1]) - 1;          // - 1 As first element (head) will be created separately from rest of data given.
    
    first = (Node*)calloc(1, sizeof(Node));  // Creating the first node.
    current = first;                         // Current pointer points to the first node now.
    current->value = atoi(argv[2]);          // Input data for first node.

    for(int i = 0; i < length; ++i)  // Making rest of the nodes for linked list.
    {
        current->next = (Node*)calloc(1, sizeof(Node));
        current = current->next;
        current->value = atoi(argv[i + 3]);
    }

    current->next = NULL;
    return first;
}

void print_nodes(Node *start)
{
    Node* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}
