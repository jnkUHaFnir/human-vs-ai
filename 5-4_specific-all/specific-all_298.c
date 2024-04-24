#include <stdio.h>
#include <stdlib.h>

void processEntityIndexes(int* indexes, int numIndexes) {
    for (int i = 0; i < numIndexes; i++) {
        printf("Index %d: %d\n", i, indexes[i]);
    }
    // Add your processing logic here
}

int main() {
    int* entityIndexes = NULL;
    int numEntities = 0;

    // Simulate adding index numbers
    for (int i = 0; i < 10; i++) {
        // Dynamically reallocate memory to store the new index
        entityIndexes = (int*)realloc(entityIndexes, (numEntities + 1) * sizeof(int));
        
        if (entityIndexes == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            // Handle error condition
            return 1;
        }

        // Add the index number
        entityIndexes[numEntities] = i;
        numEntities++;
    }

    // Process the entity indexes
    processEntityIndexes(entityIndexes, numEntities);

    // Free the dynamically allocated memory
    free(entityIndexes);

    return 0;
}
