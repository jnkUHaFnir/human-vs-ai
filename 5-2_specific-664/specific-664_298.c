#include <stdio.h>
#include <stdlib.h>

void processEntities(int* entityIndexes, int numEntities) {
    // Process entities
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity with index %d\n", entityIndexes[i]);
    }
}

int main() {
    int numEntities = 3000; // Number of entities to process
    int* entityIndexes = NULL;
    
    // Dynamically allocate memory for entity indexes
    entityIndexes = (int*)malloc(numEntities * sizeof(int));

    // Check if memory allocation was successful
    if (entityIndexes == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Populate entity indexes (just an example, you would fill this based on your needs)
    for (int i = 0; i < numEntities; i++) {
        entityIndexes[i] = i; // Storing index in the array
    }

    // Call function to process entities
    processEntities(entityIndexes, numEntities);

    // Free dynamically allocated memory
    free(entityIndexes);

    return 0;
}
