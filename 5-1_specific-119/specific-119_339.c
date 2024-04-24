#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 18446744073709551615 // Maximum value for A

typedef struct Data {
    unsigned long long A;
    char *B;
    struct Data *next;
} Data;

Data *hashTable[MAX_SIZE];

void set(unsigned long long A, char *B) {
    unsigned long long index = A % MAX_SIZE;

    Data *newNode = malloc(sizeof(Data));
    newNode->A = A;
    newNode->B = strdup(B);
    newNode->next = NULL;

    // Insert at the beginning of the linked list at hashTable[index]
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
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
    set(123, "hello");
    set(456, "world");

    printf("%s\n", get(123)); // Output: hello
    printf("%s\n", get(456)); // Output: world
    printf("%s\n", get(789)); // Output: (null)

    return 0;
}
