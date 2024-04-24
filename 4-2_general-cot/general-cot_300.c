#include <stdio.h>
#include <stdlib.h>

void processEntities(int *entityIndexes, int numEntities) {
    // Process entities using the array of entity indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity with index: %d\n", entityIndexes[i]);
    }
}

int main() {
    int maxEntities = 3000;
    int numEntities = 0; // Keep track of the number of entities added to the list

    // Dynamically allocate memory for the array of entity indexes
    int* entityIndexes = (int*)malloc(maxEntities * sizeof(int));
    if (entityIndexes == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Add entities to the array of indexes
    for (int i = 0; i < maxEntities; i++) {
        entityIndexes[numEntities++] = i; // Add indexes of entities
    }

    // Pass the array of entity indexes to the processing function
    processEntities(entityIndexes, numEntities);

    // Free dynamically allocated memory to avoid memory leaks
    free(entityIndexes);

    return 0;
}
