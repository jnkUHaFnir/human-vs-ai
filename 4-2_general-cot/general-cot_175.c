#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a node in a linked list
typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Function to append a character to the linked list
void append(Node** headRef, char data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    Node* last = *headRef;

    new_node->data = data;
    new_node->next = NULL;

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Function to free the memory allocated for the linked list
void freeList(Node* head) {
    Node* current = head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int read_string() {
    Node* head = NULL;
    int counter = 0;
    char input;

    while ((input = getchar()) != '\n') {
        printf("%c\n", input);
        append(&head, input);
        counter++;
    }

    printf("Length of string: %d\n", counter);

    // Print the stored characters
    Node* current = head;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
    printf("\n");

    // Free the allocated memory
    freeList(head);

    return counter;
}

int main() {
    read_string();
    return 0;
}
