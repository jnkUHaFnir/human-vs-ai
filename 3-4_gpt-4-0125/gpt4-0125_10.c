temp->next = new;
#include <stdlib.h> // Make sure to include stdlib for malloc

typedef struct node {
    int data;
    struct node *next;
} node;

void insert(node **head, int x) {
    node *new = malloc(sizeof(node));
    new->data = x;
    new->next = NULL;

    // If the list is empty, directly assign *head to new
    if (*head == NULL) {
        *head = new;
    } else {
        node *temp = *head;

        // Iterate until we reach the last node
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // Now temp points to the last node of the list
        temp->next = new; // Append new node here
    }
}
