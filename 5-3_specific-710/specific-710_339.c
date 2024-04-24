#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 18446744073709551615UL

typedef struct data {
    unsigned long long A;
    char *B;
    struct data *next;
    struct data *prev;
} Data;

Data *hashTable[MAX] = {NULL};

void set(unsigned long long A, char *B) {
    // Create a new data entry
    Data *newData = (Data *)malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B);
    newData->next = NULL;
    newData->prev = NULL;

    // Add to hash table
    hashTable[A] = newData;
}

char* get(unsigned long long A) {
    // Find data in hash table
    Data *current = hashTable[A];

    if (current == NULL) {
        return NULL; // Data not found
    }

    return current->B; // Return the corresponding string
}

int main() {
    set(123, "abc");
    set(456, "def");

    printf("%s\n", get(123)); // Should print "abc"
    printf("%s\n", get(456)); // Should print "def"
    printf("%s\n", get(789)); // Should print "(null)"

    return 0;
}
