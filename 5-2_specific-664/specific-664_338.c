#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 18446744073709551615ULL // Maximum value of A for the hash table

typedef struct {
    unsigned long long A;
    char *B;
} Data;

Data *hashTable[MAX_DATA];

void set(unsigned long long A, char *B) {
    Data *newData = (Data *)malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B); // Copy the string to prevent issues with changing input
    hashTable[A % MAX_DATA] = newData; // Use modulo operation to get index in hash table
}

char *get(unsigned long long A) {
    if (hashTable[A % MAX_DATA] != NULL && hashTable[A % MAX_DATA]->A == A) {
        return hashTable[A % MAX_DATA]->B;
    } else {
        return NULL; // Not found
    }
}

int main() {
    set(123, "abc");
    set(456, "def");

    char *result1 = get(123);
    char *result2 = get(456);
    char *result3 = get(789);

    if (result1) {
        printf("Result 1: %s\n", result1);
        free(result1);
    } else {
        printf("Data for key 123 not found.\n");
    }

    if (result2) {
        printf("Result 2: %s\n", result2);
        free(result2);
    } else {
        printf("Data for key 456 not found.\n");
    }

    if (result3) {
        printf("Result 3: %s\n", result3);
        free(result3);
    } else {
        printf("Data for key 789 not found.\n");
    }

    // Free allocated memory
    for (int i = 0; i < MAX_DATA; i++) {
        if (hashTable[i] != NULL) {
            free(hashTable[i]->B);
            free(hashTable[i]);
        }
    }

    return 0;
}
