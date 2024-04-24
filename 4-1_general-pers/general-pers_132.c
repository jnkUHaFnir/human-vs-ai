#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void insert(node **head, int x) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = x;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode; // if the list is empty, make the new node the head
        return;
    }

    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Sample main function to demonstrate the usage
int main() {
    node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    // Print the linked list to verify
    node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    
    return 0;
}
