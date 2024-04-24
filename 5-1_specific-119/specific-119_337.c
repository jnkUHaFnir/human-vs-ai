#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_LENGTH 100

typedef struct Data {
    unsigned long long A;
    char B[MAX_DATA_LENGTH];
    struct Data* next;
} Data;

#define HASH_SIZE 1000000

Data* hashTable[HASH_SIZE];

unsigned long long hashFunction(unsigned long long key) {
    return key % HASH_SIZE;
}

void set(unsigned long long A, char* B) {
    unsigned long long index = hashFunction(A);

    Data* newData = (Data*)malloc(sizeof(Data));
    if (newData == NULL) {
        // handle memory allocation error
        return;
    }
    newData->A = A;
    strncpy(newData->B, B, MAX_DATA_LENGTH - 1);
    newData->B[MAX_DATA_LENGTH - 1] = '\0';
    newData->next = hashTable[index];
    hashTable[index] = newData;
}

Data* get(unsigned long long A) {
    unsigned long long index = hashFunction(A);
    Data* current = hashTable[index];

    while (current != NULL) {
        if (current->A == A) {
            return current;
        }
        current = current->next;
    }

    return NULL; // A not found
}

int main() {
    set(12345, "Hello");
    set(54321, "World");

    unsigned long long key = 12345;
    Data* result = get(key);

    if (result != NULL) {
        printf("Found data for key %llu: %s\n", key, result->B);
    } else {
        printf("Data not found for key %llu\n", key);
    }

    return 0;
}
