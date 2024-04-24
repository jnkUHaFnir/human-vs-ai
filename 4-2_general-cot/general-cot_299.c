#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTITIES 3000

void processEntities(int* entityIndexes, int numEntities) {
    // Process the entities using the indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Entity Index: %d\n", entityIndexes[i]);
    }
}

int main() {
    int numEntities = 0;
    // Dynamically allocate memory for the entity indexes
    int* entityIndexes = (int*)malloc(MAX_ENTITIES * sizeof(int));
    
    // Check if memory allocation was successful
    if (entityIndexes == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Return error code
    }
    
    // Add entities to the indexes array
    entityIndexes[numEntities++] = 10;
    entityIndexes[numEntities++] = 20;
    
    // Pass the entity indexes to the processing function
    processEntities(entityIndexes, numEntities);
    
    // Free the allocated memory after its use
    free(entityIndexes);
    
    return 0;
}
