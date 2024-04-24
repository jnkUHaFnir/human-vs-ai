#include <stdio.h>
#include <stdlib.h>

void processEntities(int* entityIndexes, int numEntities) {
    // Process the entities using the indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity with index: %d\n", entityIndexes[i]);
    }
}

int main() {
    // Define variables
    int* entityIndexes = NULL;
    int numEntities = 0;

    // Dynamically allocate memory for the entityIndexes array
    // You can adjust the initial size as needed
    entityIndexes = (int*)malloc(sizeof(int));

    if (entityIndexes == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        return 1;
    }

    // Add some indexes to the array (you can do this dynamically as needed)
    for (int i = 0; i < 10; i++) {
        entityIndexes[numEntities] = i; // Assign index
        numEntities++; // Increment the counter
        entityIndexes = (int*)realloc(entityIndexes, (numEntities + 1) * sizeof(int)); // Resize the array
    }

    // Process the entities (passing the array and the number of entities)
    processEntities(entityIndexes, numEntities);

    // Free the dynamically allocated memory
    free(entityIndexes);

    return 0;
}
