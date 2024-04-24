#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

void insert(node **head, int x) {
    node *newNode = malloc(sizeof(node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.");
        exit(1); // Handle memory allocation failure
    }
    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; // If list is empty, make new node the head
    } else {
        node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next; // Traverse to the end of the list
        }
        temp->next = newNode; // Link new node at the end
    }
}

int main() {
    node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    node *current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    return 0;
}
