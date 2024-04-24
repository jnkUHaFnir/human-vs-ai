#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 18446744073709551615

typedef struct {
    unsigned long long A;
    char *B;
} Data;

Data *hashTable[MAX_SIZE];

void set(unsigned long long A, char *B) {
    if (A >= MAX_SIZE) {
        printf("Error: A value exceeds maximum size\n");
        return;
    }

    Data *newData = (Data *)malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B); // Copy the string

    hashTable[A] = newData;
}

char *get(unsigned long long A) {
    if (A >= MAX_SIZE || hashTable[A] == NULL) {
        return NULL;
    }

    return hashTable[A]->B;
}

int main() {
    // Testing the set and get functions
    set(123, "Hello");
    set(456, "World");

    printf("Value at key 123: %s\n", get(123)); // Output: Hello
    printf("Value at key 456: %s\n", get(456)); // Output: World
    printf("Value at key 789: %s\n", get(789)); // Output: (null)

    return 0;
}
