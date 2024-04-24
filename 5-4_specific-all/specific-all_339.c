#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 18446744073709551616 // Size of the hash table (assuming each unique value A maps to a unique index)

// Define the structure for data node
typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
} Data;

// Initialize the hash table
Data *hashTable[SIZE] = {NULL};

// Function to set a new data entry
void set(unsigned long long A, char *B) {
    // Create a new data node
    Data *newData = malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B); // Duplicate the string since we don't know its lifetime
    newData->next = NULL;

    // Calculate the index based on A
    unsigned long long index = A % SIZE;

    // If no data exists at index, insert as the head
    if (hashTable[index] == NULL) {
        hashTable[index] = newData;
    } else {  // If data already exists, append to the end of the linked list
        Data *curr = hashTable[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newData;
    }
}

// Function to get the data corresponding to a given A
char* get(unsigned long long A) {
    // Calculate the index based on A
    unsigned long long index = A % SIZE;

    // Traverse through the linked list at the index
    Data *curr = hashTable[index];
    while (curr != NULL) {
        if (curr->A == A) {
            return curr->B;
        }
        curr = curr->next;
    }

    return NULL; // Return NULL if data not found for A
}

// Example usage
int main() {
    set(123, "abc");
    set(456, "def");

    printf("Data for A=123: %s\n", get(123));
    printf("Data for A=456: %s\n", get(456));
    printf("Data for A=789: %s\n", get(789));

    return 0;
}
