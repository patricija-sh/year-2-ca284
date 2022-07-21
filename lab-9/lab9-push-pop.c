// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: push-pop.c
Functions: main, add_nodes, pop, push, print_nodes
Parameters: list of ints
Returns: Node
Description: Reads in an array of integers and adds makes them to a linked list, then deletes last two elements and adds two
             elements given in command line.
Author: Patricija Shalkauskaite
Date: 19-11-2021
*/

// Define structure type Node.
typedef struct Node Node;

struct Node
{
    int value;
    Node *next;
    Node *prev;
};

// Initialising function(s).
Node *add_nodes(char *argv[]);     // Add nodes to a linked list.
Node *pop(Node *head);             // Remove the last node from a linked list.
Node *push(Node *head, int data);  // Add a node to the end of a linked list.
void print_nodes(Node *head);      // Print out nodes in linked list.

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    Node *head = NULL;  // Initialising head pointer for linked list.

    head = add_nodes(argv);  // head will refer to the start of the linked list built by function called.

    for(int i = 0; i < 2; ++i)  // Remove the last element from the linked list twice.
    {
        head = pop(head);
    }

    for(int i = 0; i < 2; ++i)  // Add element to the end of the linked list twice.
    {
        head = push(head, atoi(argv[argc - 2 + i]));  // - 2 to start at second last element in command line.
    }

    print_nodes(head);

    return(0);
}   // End of main function

// Building initialised functions.
Node *add_nodes(char *argv[])
{
    // Defining variables.
    Node *current, *head, *prev;            // Declaring three pointers.
    int length = atoi(argv[1]) - 1;         // E.g. 7 elements but 1st is for head so the for loop only needs 6 elements.
    
    head = (Node*)calloc(1, sizeof(Node));  // Creating the first node.
    current = head;                         // Current pointer points to the first node now.
    current->value = atoi(argv[2]);         // Input data for first node.

    for(int i = 0; i < length; ++i)
    {
        current->next = (Node*)calloc(1, sizeof(Node));
        prev = current;
        current = current->next;
        current->value = atoi(argv[i + 3]);  // + 3 to skip the program name, then amount of elements and first element (head).
        current->prev = prev;
    }
    current->next = NULL;

    return head;
}

Node *pop(Node *head)
{
    // Defining variables.
    Node *temp = NULL;
    Node *p = head;

    while(p->next != NULL)  // While the next node does not point to NULL.
    {
        p = p->next;
    }
    
    temp = p->prev;    // Save previous node to temp as we'll delete what p points to.
    temp->next = NULL;
    free(p);

    return head;
}

Node *push(Node *head, int data)
{
    // Defining variables.
    Node *temp = NULL;
    Node *p = head;

    temp = (Node*)calloc(1, sizeof(Node));  // Assign space for temp and create appropriate pointers for the new node.
    temp->prev = NULL;
    temp->value = data;
    temp->next = NULL;

    while(p->next != NULL)
    {
        p = p->next;
    }

    p->next = temp;  // The pointer adds temp to the list.
    temp->prev = p;  // temp points back to p so now they're linked together.

    return head; 
}

void print_nodes(Node *head)
{
    Node *p = NULL;
    for(p = head; p != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}
