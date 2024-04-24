#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_BUCKETS 1000000

typedef struct Node {
    unsigned long long A;
    char *B;
    struct Node *next;
} Node;

Node *hashTable[MAX_NUM_BUCKETS];

void set(unsigned long long A, char *B) {
    // Create a new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->A = A;
    newNode->B = strdup(B);
    newNode->next = NULL;

    // Calculate hash value
    int index = A % MAX_NUM_BUCKETS;

    // Insert the new node at the beginning of the linked list
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

char *get(unsigned long long A) {
    // Calculate hash value
    int index = A % MAX_NUM_BUCKETS;

    // Traverse the linked list to find the node with matching A
    Node *current = hashTable[index];
    while (current != NULL) {
        if (current->A == A) {
            return current->B;
        }
        current = current->next;
    }

    return NULL;  // A not found
}

int main() {
    // Test the set and get functions
    set(123, "abc");
    set(456, "def");

    printf("A: 123, B: %s\n", get(123));
    printf("A: 456, B: %s\n", get(456));

    return 0;
}
