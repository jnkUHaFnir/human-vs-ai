#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
typedef struct Node {
    char data;
    struct Node* next;
} Node;

int read_string() {
    Node* head = NULL; // Initialize head of the linked list
    Node* tail = NULL; // Initialize tail of the linked list

    int counter = 0;

    char input;
    while ((input = getchar()) != '\n') {
        // Create a new node for the character
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            return -1;
        }
        newNode->data = input;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        counter++;
    }

    // Print and free the linked list
    Node* current = head;
    while (current != NULL) {
        printf("%c\n", current->data);
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    printf("Length of string: %d\n", counter);

    return 0;
}

int main() {
    read_string();
    return 0;
}
