// Import libraries.
#include <stdio.h>
#include <stdlib.h>

/*
Name: inside-the-queue.c
Functions: main, add_nodes, insert_node, print_nodes
Parameters: two ints.
Returns: Nodes
Description: Reads in an element that's in our hard-coded linked list and inserts a new node given after that element.
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
Node *add_nodes(int *num_list, int length);   // Add nodes to a linked list.
Node *insert_node(Node *head, int position, int data);  // Insert a new node after the position specified.
void print_nodes(Node *head);    // Print out nodes in linked list.

int main(int argc, char *argv[])
{   // Start of main function.

    // Defining variables.
    Node *head = NULL;  // Initialising head pointer for linked list.
    int num_list[10] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};  // The linked list we'll use to insert nodes in between it.
    int list_length = sizeof(num_list) / sizeof(int);

    head = add_nodes(num_list, list_length);  // head will refer to the start of the linked list built by function called.
    head = insert_node(head, atoi(argv[1]), atoi(argv[2]));  // passing two command-line args to insert new node into linked list.

    print_nodes(head);

    return(0);
}   // End of main function.

// Building initialised functions.
Node *add_nodes(int *num_list, int length)
{
    // Defining variables.
    Node *current, *head, *prev;            // Declaring three pointers.

    head = (Node*)calloc(1, sizeof(Node));  // Creating the first node.
    current = head;                         // Current pointer points to the first node now.
    current->value = num_list[0];           // Input data for first node.

    for(int i = 0; i < length; ++i)
    {
        current->next = (Node*)calloc(1, sizeof(Node));
        prev = current;
        current = current->next;
        current->value = num_list[i + 1];  // + 1 to not count the first node (that's head).
        current->prev = prev;
    }
    current->next = NULL;

    return head;
}

Node *insert_node(Node *head, int position, int data)
{
    // Defining variables.
    Node *temp = NULL;  // Pointer that will be to the right of the new node.
    Node *p = head;     // Pointer that will be to the left of the new node.
    Node *new_node = NULL;

    new_node = (Node*)calloc(1, sizeof(Node));  // Allocating space for new node and creating value for it.
    new_node->prev = NULL;
    new_node->value = data;
    new_node->next = NULL;

    while(p->value != position)  // While the current node's value doesn't match the node (position) specified.
    {
        p = p->next;
    }

    temp = p->next;
    p->next = new_node;     // left node linked to new node.
    temp->prev = new_node;  // right node linked to new node.
    new_node->next = temp;  // new_node is linked to the right node
    new_node->prev = p;     // new_node is linked to the left node

    return head;


}

void print_nodes(Node *head)
{
    Node *p = NULL;
    for(p = head; p->next != NULL; p = p->next)
    {
        printf("%d\n", p->value);
    }
}
