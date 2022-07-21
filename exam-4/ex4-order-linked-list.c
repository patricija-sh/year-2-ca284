// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: ex4-order-linked-list.c
Functions: main, get_nodes, check_descending, print_nodes
Parameters: an array of numbers (char *argv[])
Returns: int
Description: Reads in an array of numbers and outputs 1 or 0 depending on whether the array is in descending order.
Author: Patricija Shalkauskaite
Date: 09-12-2021
*/

typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

// Initialising function(s).
Node* get_nodes(char *argv[], int length);  // Add the numbers to the linked list.
int check_descending(Node *start, int length);  // Check if the linked list is in descending order.

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    Node *start = NULL;
    int length = argc - 1;

    start = get_nodes(argv, length);
    printf("%d\n", check_descending(start, length));

    free(start);

    return 0;
}   // End of main function.

/*
    Function Name: get_nodes
    Parameters: char *argv[], int length
    Description: Puts the numbers into a linked list.
*/

Node* get_nodes(char *argv[], int length)
{
    Node *current, *first, *prev;  // Declaring three pointers.
    first = (Node*)calloc(1, sizeof(Node));  // Creating the first node.
    current = first;  // Current pointer points to the first node now.
    
    // Input data for first node.
    current->value = atoi(argv[1]);

    for(int i = 1; i < length; ++i)
    {
        current->next = (Node*)calloc(1, sizeof(Node));  // Assign adequate space.
        prev = current;
        current = current->next;
        current->value = atoi(argv[i + 1]);
        current->prev = prev;
    }

    current->next = NULL;
    return first;
}

/*
    Function Name: check_descending
    Parameters: Node *start, int length.
    Description: For each element, check if the current one is bigger than the next.
                 If the count of the i increment is the same as the linked list's length - 1,
                 then each element is smaller than the one before it.
*/

int check_descending(Node *start, int length)
{
    Node* p = NULL;
    int i = 0;
    for(p = start; p->next != NULL; p = p->next)
    {
        if(p->value >= p->next->value)  // Comparing the current value with the next one in the linked list.
        {
            i += 1;
        }
    }

    if(i == length - 1)  // - 1 because the last node isn't compared with whatever is next after it (that would be NULL).
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
