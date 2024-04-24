#include <stdio.h>
#include <stdlib.h>

void processEntities(int* entityIndexes, int numEntities) {
    // Process the entities based on the indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity with index: %d\n", entityIndexes[i]);
    }
}

int main() {
    int numEntities = 3000; // For example, number of entities
    // Dynamically allocate memory for the array of entity indexes
    int* entityIndexes = (int*)malloc(numEntities * sizeof(int));

    if (entityIndexes == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Populate the array with indexes (for demonstration purposes)
    for (int i = 0; i < numEntities; i++) {
        entityIndexes[i] = i;
    }

    // Pass the array and the number of entities to the processing function
    processEntities(entityIndexes, numEntities);

    // Free the dynamically allocated memory
    free(entityIndexes);

    return 0;
}
