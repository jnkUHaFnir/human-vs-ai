#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 18446744073709551616 // Maximum value for A

typedef struct Node {
    unsigned long long key;
    char *value;
    struct Node *next;
} Node;

Node *hashTable[MAX_SIZE];

void set(unsigned long long A, char *B) {
    // Create a new node
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = A;
    newNode->value = (char*)malloc(strlen(B) + 1); // Allocate memory for the string
    strcpy(newNode->value, B);
    newNode->next = NULL;
    
    // Insert into hash table
    unsigned long long index = A % MAX_SIZE;
    if (hashTable[index] != NULL) {
        newNode->next = hashTable[index];
    }
    hashTable[index] = newNode;
}

char* get(unsigned long long A) {
    // Search for the key in the hash table
    unsigned long long index = A % MAX_SIZE;
    Node *current = hashTable[index];
    while (current != NULL) {
        if (current->key == A) {
            return current->value;
        }
        current = current->next;
    }
    
    return NULL; // Key not found
}

int main() {
    set(123, "hello");
    set(456, "world");

    // Test get function
    char* result1 = get(123);
    if (result1 != NULL) {
        printf("Result for key 123: %s\n", result1);
    } else {
        printf("Key 123 not found\n");
    }

    char* result2 = get(456);
    if (result2 != NULL) {
        printf("Result for key 456: %s\n", result2);
    } else {
        printf("Key 456 not found\n");
    }

    return 0;
}
