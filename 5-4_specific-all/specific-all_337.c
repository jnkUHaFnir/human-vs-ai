#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 18446744073709551615 // Maximum value for A

typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
} Data;

#define HASH_SIZE 10000019 // Prime number for hash table size

Data *hashTable[HASH_SIZE] = {0}; // Initialize hash table to NULL pointers

void set(unsigned long long A, char *B) {
    // Create a new data entry
    Data *newData = (Data *)malloc(sizeof(Data));
    if (!newData) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    newData->A = A;
    newData->B = strdup(B);
    newData->next = NULL;

    // Calculate hash value
    unsigned long long index = A % HASH_SIZE;

    // Insert the new data at the beginning of the linked list at the hash index
    newData->next = hashTable[index];
    hashTable[index] = newData;
}

char* get(unsigned long long A) {
    // Calculate hash value
    unsigned long long index = A % HASH_SIZE;

    // Traverse the linked list at the hash index to find the data with given A
    Data *current = hashTable[index];
    while (current != NULL) {
        if (current->A == A) {
            return current->B; // Found the data, return B
        }
        current = current->next;
    }

    return NULL; // Data not found
}

int main() {
    set(12345, "Hello");
    set(54321, "World");

    printf("%s\n", get(12345)); // Output: Hello
    printf("%s\n", get(54321)); // Output: World
    printf("%s\n", get(9999)); // Output: (null)

    return 0;
}
