#include <stdlib.h> // Make sure to include for malloc()

typedef struct node {
    int data;
    struct node *next;
} node;

void insert(node **head, int x) {
    node *new = malloc(sizeof(node));
    if (new == NULL) { // Always good to check if malloc didn't fail
        return;
    }

    new->data = x;
    new->next = NULL;

    if (*head == NULL) {
        // The list is empty, so set head to the new node
        *head = new;
    } else {
        // The list isn't empty, so find the last node
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        // temp now points to the last node
        temp->next = new;
    }
}
