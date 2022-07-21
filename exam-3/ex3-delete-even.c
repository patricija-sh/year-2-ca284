// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: delete-even.c
Functions: main, add_nodes, find_event_count, delete_evens, print_nodes, get_sum.
Parameters: array of ints.
Returns: int
Description: Reads in an array of integers, puts them all into a linked list, then it finds how many even numbers were inputted,
and deletes even numbers for as many as there were given. Finally, the odd linked list is passed to a summation function that gets its sum.
Author: Patricija Shalkauskaite
Date: 25-11-2021
*/

// Defining structure type Node.
typedef struct Node Node;

struct Node  // A doubly linked list.
{
    int value;
    Node *next;
    Node *prev;
};

// Function prototypes.
Node *add_nodes(char *argv[], int length);
int find_even_count(char *argv[], int length);
Node *delete_evens(Node *start);  //, int even_count);
void print_nodes(Node *start);
void get_sum(int *sum, Node *start);

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    Node *start = NULL;
    int length = argc - 1;
    int sum = 0;

    int even_count = find_even_count(argv, length);

    start = add_nodes(argv, length);

    for(int i = 0; i < even_count; ++i)
    {
        start = delete_evens(start); //, even_count);
    }

    get_sum(&sum, start);

    print_nodes(start);
    printf("%d\n", sum);

    return(0);
}

Node *add_nodes(char *argv[], int length)
{
    Node *current, *first, *prev;  // Declaring three pointers.

    first = (Node*)calloc(1, sizeof(Node));  // Creating the first node.
    
    current = first;                         // Current pointer points to the first node now.
    current->value = atoi(argv[1]);          // Input data for first node.

    for(int i = 0; i < length - 1; ++i)  // Putting the rest of the values in the linked list.
    {
        current->next = (Node*)calloc(1, sizeof(Node));
        prev = current;
        current = current->next;
        current->value = atoi(argv[i + 2]);
        current->prev = prev;
    }

    current->next = NULL;
    return first;
}

int find_even_count(char *argv[], int length)
{
    // Defining variables.
    int count = 0;

    for(int i = 0; i < length; ++i)
    {
        if(atoi(argv[i + 1]) % 2 == 0)  // If the number is even, record it.
        {
            count += 1;
        }
    }

    return count;
}

Node *delete_evens(Node *start)
{
    Node *left = NULL;   // The node pointer to the left of to_delete pointer.
    Node *right = NULL;  // The node pointer to the right of to_delete pointer.
    Node *to_delete = start;

    while(to_delete->value % 2 != 0 && to_delete->next != NULL)  // Whilst we haven't come across an even number or the end of the list.
    {
        to_delete = to_delete->next;  // Keep going.
    }

    if(to_delete->next == NULL)  // If the even number is at the end of the list, deleting the node will be different than if it were in the start/middle.
    {
        left = to_delete->prev;    // Save previous node to left as we'll delete what to_delete points to.
        left->next = NULL;
    }
    else if(to_delete->prev == NULL)  // If the first node is even, make the next one point to NULL.
    {
        start = to_delete->next;      // Save previous node to right as we'll delete what to_delete points to.
        start->prev = NULL;
    }
    else  // Else the node to delete will be in the middle.
    {
        left = to_delete->prev;
        right = to_delete->next;

        left->next = right;  // Left node will connect with the right node and vice versa.
        right->prev = left;
    }
        
    free(to_delete);  // We're done with this pointer.

    return start;
}

void get_sum(int *sum, Node *start)
{
    Node *p = start;

    while(p != NULL)
    {
        *sum += p->value;
        p = p->next;
    }
}

void print_nodes(Node *start)
{
    Node* p = NULL;
    for(p = start; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}
