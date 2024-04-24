#include <stdio.h>
#include <stdlib.h>

void processEntities(int* entityIndexes, int numEntities) {
    // Process the entities using the indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity with index: %d\n", entityIndexes[i]);
    }
}

int main() {
    int numGameEntities = 3000; // Total number of game entities
    int numEntitiesAdded = 0; // Number of entities added to the list

    // Dynamically allocate memory for storing entity indexes
    int* entityIndexes = NULL;

    // Add entities to the list (just an example, you can add entities as needed)
    for (int i = 0; i < numGameEntities; i++) {
        if (/* condition to add entity */) {
            // Increase the number of entities added
            numEntitiesAdded++;

            // Resize the entityIndexes array to hold the new index
            entityIndexes = (int*)realloc(entityIndexes, numEntitiesAdded * sizeof(int));
            if (entityIndexes == NULL) {
                // Handle memory allocation failure
                printf("Memory allocation failed. Exiting...\n");
                exit(1);
            }

            // Add the index of the new entity
            entityIndexes[numEntitiesAdded - 1] = i; // -1 because indexing starts from 0
        }
    }

    // Process the entities
    processEntities(entityIndexes, numEntitiesAdded);

    // Free the dynamically allocated memory
    free(entityIndexes);

    return 0;
}
