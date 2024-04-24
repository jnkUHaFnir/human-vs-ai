#include <stdio.h>
#include <stdlib.h>

void processEntities(int* indexes, int numEntities) {
    // Process entities using the indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity with index %d\n", indexes[i]);
    }
}

int main() {
    int maxEntities = 3000; // Maximum game entities
    int* indexes = (int*)malloc(maxEntities * sizeof(int)); // Dynamically allocate memory for indexes
    int numEntities = 0;

    // Add indexes to the array
    indexes[numEntities++] = 1;
    indexes[numEntities++] = 2;
    indexes[numEntities++] = 3;

    // Process the entities
    processEntities(indexes, numEntities);

    // Free the memory used for the indexes
    free(indexes);

    return 0;
}
