#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_ENTRIES 18446744073709551615

typedef struct {
    unsigned long long A;
    char *B;
} Data;

Data *dataEntries[MAX_DATA_ENTRIES];

void set(unsigned long long A, char *B) {
    if (dataEntries[A] == NULL) {
        Data *newData = (Data *)malloc(sizeof(Data));
        newData->A = A;
        newData->B = strdup(B);
        dataEntries[A] = newData;
    } else {
        // Data entry already exists for the given A, update B
        free(dataEntries[A]->B);
        dataEntries[A]->B = strdup(B);
    }
}

char *get(unsigned long long A) {
    if (dataEntries[A] != NULL) {
        return dataEntries[A]->B;
    } else {
        return NULL;
    }
}

int main() {
    set(1234, "Hello");
    set(5678, "World");

    printf("%s\n", get(1234)); // Output: Hello
    printf("%s\n", get(5678)); // Output: World

    // Free allocated memory
    free(dataEntries[1234]->B);
    free(dataEntries[1234]);
    free(dataEntries[5678]->B);
    free(dataEntries[5678]);

    return 0;
}
