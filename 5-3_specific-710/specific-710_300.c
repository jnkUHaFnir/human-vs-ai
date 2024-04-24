#include <stdio.h>
#include <stdlib.h>

void processEntities(int* indexes, int numEntities) {
    // Process the entities
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity with index: %d\n", indexes[i]);
    }
}

int main() {
    int numEntities = 3000; // Maximum number of entities (can be dynamic)
    int* entityIndexes = (int*)malloc(numEntities * sizeof(int)); // Allocate memory for entity indexes

    if (entityIndexes == NULL) {
        // Handle allocation failure
        printf("Memory allocation failed.\n");
        return 1;
    }

    int numEntitiesAdded = 0;

    // Add entities to the array
    for (int i = 0; i < numEntities; i++) {
        if (/* condition to add entity */) {
            entityIndexes[numEntitiesAdded] = i; // Add entity index to the array
            numEntitiesAdded++;
        }
    }

    // Process the entities
    processEntities(entityIndexes, numEntitiesAdded);

    // Free the dynamically allocated memory
    free(entityIndexes);

    return 0;
}
