#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA 18446744073709551615

typedef struct {
    unsigned long long A;
    char *B;
} Data;

Data *hashTable[MAX_DATA];

void set(unsigned long long A, char *B) {
    Data *newData = (Data *)malloc(sizeof(Data));
    newData->A = A;
    newData->B = strdup(B);
    
    hashTable[A] = newData;
}

char *get(unsigned long long A) {
    if(hashTable[A] != NULL) {
        return hashTable[A]->B;
    } else {
        return NULL;
    }
}

int main() {
    set(1234, "hello");
    printf("%s\n", get(1234));
    
    return 0;
}
