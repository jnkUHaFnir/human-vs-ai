#include <stdio.h>
#include <stdlib.h>

void processEntities(int* indexes, int numEntities) {
    // Process the entities using the indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity at index %d\n", indexes[i]);
    }
}

int main() {
    int* indexes = NULL;
    int numEntities = 0;
    int maxEntities = 0;

    // Add entities to the array
    for (int i = 0; i < 3000; i++) {
        // Check if resizing is needed
        if (numEntities >= maxEntities) {
            maxEntities = (maxEntities == 0) ? 10 : maxEntities * 2;
            indexes = realloc(indexes, maxEntities * sizeof(int));
            if (indexes == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                exit(1);
            }
        }

        // Add the entity index
        indexes[numEntities] = i;
        numEntities++;
    }

    // Process the entities
    processEntities(indexes, numEntities);

    // Free the allocated memory
    free(indexes);

    return 0;
}
