#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 18446744073709551615 // Maximum possible value for A

// Define the data structure for each element (key-value pair)
typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
} Data;

// Define the Hash Table
Data *hashTable[TABLE_SIZE] = {NULL};

// Hash function
unsigned long long hash(unsigned long long A) {
    return A % TABLE_SIZE;
}

// Function to set a new value in the Hash Table
void set(unsigned long long A, char *B) {
    // Create new data
    Data *newData = (Data *)malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B); // Duplicate the string so ownership is transferred
    newData->next = NULL;

    // Calculate hash value
    unsigned long long index = hash(A);

    // Insert into hash table (at the beginning of the linked list)
    newData->next = hashTable[index];
    hashTable[index] = newData;
}

// Function to get a value from the Hash Table
char* get(unsigned long long A) {
    // Calculate hash value
    unsigned long long index = hash(A);

    // Traverse the linked list at the hash index
    Data *current = hashTable[index];
    while (current != NULL) {
        if (current->A == A) {
            return current->B;
        }
        current = current->next;
    }

    return NULL; // Value not found
}

// Cleanup function to free memory
void cleanup() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Data *current = hashTable[i];
        while (current != NULL) {
            Data *temp = current->next;
            free(current->B); // Free the duplicated string
            free(current);
            current = temp;
        }
    }
}

// Test the functions
int main() {
    set(123, "Hello");
    set(456, "World");

    printf("Value at key 123: %s\n", get(123));
    printf("Value at key 456: %s\n", get(456));
    printf("Value at key 789: %s\n", get(789));

    cleanup();

    return 0;
}
