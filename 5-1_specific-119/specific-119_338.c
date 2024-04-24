#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 18446744073709551615UL

typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
} Data;

Data *hashTable[MAX_SIZE];

void set(unsigned long long A, char *B) {
    Data *newData = (Data *)malloc(sizeof(Data));
    if (!newData) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    newData->A = A;
    newData->B = strdup(B); // strdup allocates memory for the string
    newData->next = NULL;

    // Calculate the hash index
    unsigned long long index = A % MAX_SIZE;

    // Insert into the hash table
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

char *get(unsigned long long A) {
    unsigned long long index = A % MAX_SIZE;
    Data *current = hashTable[index];

    while (current != NULL) {
        if (current->A == A) {
            return current->B;
        }
        current = current->next;
    }

    return NULL; // A not found
}

int main() {
    set(123, "Hello");
    set(456, "World");

    printf("%s\n", get(123)); // Output: Hello
    printf("%s\n", get(456)); // Output: World
    printf("%s\n", get(789)); // Output: (null)

    return 0;
}
