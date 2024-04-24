#include <stdio.h>
#include <stdlib.h>

void processEntities(int* entityIndexes, int numEntities) {
    // Process the entities using the index array
    for (int i = 0; i < numEntities; i++) {
        // Process entity at index entityIndexes[i]
        printf("Processing entity at index %d\n", entityIndexes[i]);
    }
}

void freeEntityIndexes(int* entityIndexes) {
    free(entityIndexes);
}

int main() {
    int numTotalEntities = 3000; // Maximum game entities
    int numEntitiesAdded = 0;

    // Dynamically allocate memory for index array
    int* entityIndexes = (int*)malloc(numTotalEntities * sizeof(int));
    if (entityIndexes == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        return 1;
    }

    // Add entities to the index array
    // For example, add entities with index 0, 1, 2
    entityIndexes[numEntitiesAdded++] = 0;
    entityIndexes[numEntitiesAdded++] = 1;
    entityIndexes[numEntitiesAdded++] = 2;

    // Pass the index array to a function for processing
    processEntities(entityIndexes, numEntitiesAdded);

    // Free dynamically allocated memory after use
    freeEntityIndexes(entityIndexes);

    return 0;
}
