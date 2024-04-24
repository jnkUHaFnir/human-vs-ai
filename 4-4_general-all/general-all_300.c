#include <stdio.h>
#include <stdlib.h>

void processEntityIndexes(int* entityIndexes, int numEntities) {
    // Process the entity indexes here
    for (int i = 0; i < numEntities; i++) {
        printf("%d ", entityIndexes[i]);
    }
    printf("\n");
}

int main() {
    int* entityIndexes = NULL;
    int numEntities = 0;
    int maxEntities = 0;

    // Read in-game entities or indexes
    for (int i = 0; i < 10; i++) {
        int newIndex = i; // Simulating reading an entity index

        // Check if space for new index is available
        if (numEntities == maxEntities) {
            maxEntities = (maxEntities == 0) ? 1 : maxEntities * 2; // Double the size
            entityIndexes = (int*)realloc(entityIndexes, maxEntities * sizeof(int));
            if (entityIndexes == NULL) {
                perror("Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
        }

        // Add new index to the array
        entityIndexes[numEntities] = newIndex;
        numEntities++;
    }

    // Pass the array to a function for processing
    processEntityIndexes(entityIndexes, numEntities);

    // Free dynamically allocated memory
    free(entityIndexes);

    return 0;
}
