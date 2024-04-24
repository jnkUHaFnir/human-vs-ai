#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 18446744073709551615 // Maximum possible value of A

// Define a structure for data
typedef struct Node {
    unsigned long long A;
    char* B;
    struct Node* next;
    struct Node* prev;
} Node;

// Hash Map to store pointers to nodes
Node* hashMap[MAX_SIZE];

// Doubly Linked List to store data
Node* head = NULL;
Node* tail = NULL;

// Function to set a new value
void set(unsigned long long A, char* B) {
    // Check if the value of A is within range
    if (A < 0 || A > MAX_SIZE) {
        printf("Error: A is out of range\n");
        return;
    }
    
    // Check if the A value already exists
    if (hashMap[A] != NULL) {
        printf("Error: A value already exists\n");
        return;
    }

    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->A = A;
    newNode->B = strdup(B); // Copy the string to avoid memory issues
    newNode->next = NULL;
    newNode->prev = NULL;

    // Append the new node to the end of the linked list
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    // Update the hash map with the pointer to the new node
    hashMap[A] = newNode;
}

// Function to get the value corresponding to A
char* get(unsigned long long A) {
    // Check if the value of A is within range
    if (A < 0 || A > MAX_SIZE) {
        printf("Error: A is out of range\n");
        return NULL;
    }

    // Retrieve the pointer from the hash map
    Node* node = hashMap[A];

    // Check if the node exists
    if (node == NULL) {
        printf("Error: A value not found\n");
        return NULL;
    }

    return node->B;
}

// Function to free all allocated memory
void cleanup() {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current->B);
        free(current);
        current = next;
    }
}

// Sample main function for demonstration
int main() {
    set(123, "abc");
    set(456, "def");

    printf("Value for key 123: %s\n", get(123));
    printf("Value for key 456: %s\n", get(456));
    printf("Value for key 789: %s\n", get(789); // Not found

    cleanup(); // Free allocated memory before exiting

    return 0;
}
