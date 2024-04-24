#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of buckets in the hash table
#define MAX_BUCKETS 100000

// Define the data structure to store the information
typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
} Data;

// Define the hash table
Data *hashTable[MAX_BUCKETS] = {NULL};

// Hash function to determine the index for the given key
int hash(unsigned long long key) {
    return (int)(key % MAX_BUCKETS);
}

// Function to set the data in the hash table
void set(unsigned long long A, char *B) {
    int index = hash(A);

    Data *newData = (Data *)malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B);
    newData->next = hashTable[index];
    hashTable[index] = newData;
}

// Function to get the data from the hash table
char* get(unsigned long long A) {
    int index = hash(A);

    Data *current = hashTable[index];
    while (current != NULL) {
        if (current->A == A) {
            return current->B;
        }
        current = current->next;
    }

    return NULL; // Data not found
}

// Function to free the memory used by the hash table
void cleanup() {
    for (int i = 0; i < MAX_BUCKETS; i++) {
        Data *current = hashTable[i];
        while (current != NULL) {
            Data *temp = current;
            current = current->next;
            free(temp->B);
            free(temp);
        }
    }
}

// Sample usage
int main() {
    set(123456, "Hello");
    set(789012, "World");

    printf("%s\n", get(123456)); // Output: Hello
    printf("%s\n", get(789012)); // Output: World
    printf("%s\n", get(999999)); // Output: (null)

    cleanup(); // Free allocated memory

    return 0;
}
