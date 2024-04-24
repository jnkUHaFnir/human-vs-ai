#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 18446744073709551615u

typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
} Data;

Data *hashTable[MAX_SIZE] = {NULL};

void set(unsigned long long A, char *B) {
    // Check if A is within the valid range
    if (A >= MAX_SIZE) {
        printf("Error: A is out of range\n");
        return;
    }

    // Create new data node
    Data *newData = (Data *)malloc(sizeof(Data));
    if (!newData) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    // Populate the data
    newData->A = A;
    newData->B = strdup(B);
    newData->next = NULL;

    // Set or update the data in the hash table
    hashTable[A] = newData;
}

void get(unsigned long long A) {
    // Check if A is within the valid range
    if (A >= MAX_SIZE) {
        printf("Error: A is out of range\n");
        return;
    }

    // Retrieve data from the hash table
    Data *current = hashTable[A];
    
    if (current) {
        printf("A: %llu, B: %s\n", current->A, current->B);
    } else {
        printf("Data not found for A: %llu\n", A);
    }
}

int main() {
    // Test the functions
    set(123456, "Test123");
    get(123456);

    set(999999, "Hello World");
    get(999999);

    get(555555); // Data not found

    return 0;
}
