#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 18446744073709551615 // Maximum value of A for the hash table size

typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
} Data;

Data *hashTable[MAX_SIZE] = {NULL}; // Initialize hash table to NULL pointers

// Hash function to determine the index for the given key A
unsigned long long hash(unsigned long long A) {
    return A % MAX_SIZE;
}

// Function to set a new data entry
void set(unsigned long long A, char *B) {
    unsigned long long index = hash(A);

    // Create new data entry
    Data *newData = (Data *)malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B); // Allocate memory for B and copy the string
    newData->next = NULL;

    // Insert into hash table
    if (hashTable[index] == NULL) {
        hashTable[index] = newData;
    } else {
        Data *current = hashTable[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newData;
    }
}

// Function to get data for a given A
char* get(unsigned long long A) {
    unsigned long long index = hash(A);

    Data *current = hashTable[index];
    while (current != NULL) {
        if (current->A == A) {
            return current->B;
        }
        current = current->next;
    }

    return NULL; // A not found
}

// Function to free memory used by the hash table
void cleanup() {
    for (int i = 0; i < MAX_SIZE; i++) {
        Data *current = hashTable[i];
        while (current != NULL) {
            Data *temp = current;
            current = current->next;
            free(temp->B);
            free(temp);
        }
    }
}

int main() {
    set(123, "Hello");
    set(456, "World");

    printf("%s\n", get(123)); // Output: Hello
    printf("%s\n", get(456)); // Output: World

    cleanup(); // Free allocated memory

    return 0;
}
