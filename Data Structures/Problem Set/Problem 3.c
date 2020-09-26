// Iterative/Recursive C program to search an element in linked list
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Link list node */
struct Node
{
    int key;
    struct Node* next;
};

typedef struct Node node;

void push(node * * head_ref, int new_key)
{
    /* allocate node */
    node* new_node = (node *) malloc(sizeof(node));

    /* put in the key  */
    new_node->key  = new_key;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* Checks whether the value x is present in linked list */
bool search_iterative(node* head, int x)
{
    node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->key == x)
            return true;
        current = current->next;
    }
    return false;
}

bool search_recursive(node * head, int x)
{
    // Base case
    if (head == NULL)
        return false;

    // If key is present in current node, return true
    if (head->key == x)
        return true;

    // Recur for remaining list
    return search(head->next, x);
}

int main()
{
    /* Start with the empty list */
    node * head = NULL;
    int x = 21;

    /* Use push() to construct below list
     14->21->11->30->10  */
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    search(head, 21)? printf("Yes") : printf("No");
    return 0;
}
