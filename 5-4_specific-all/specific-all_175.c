#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    char input;

    while ((input = getchar()) != '\n') {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = input;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("String stored: ");
    Node* current = head;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->next;
    }
    printf("\n");

    // Free the memory used by the linked list
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
