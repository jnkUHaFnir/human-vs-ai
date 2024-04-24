#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTITIES 3000

void processEntities(int* entityIndexes, int numEntities) {
    // Process the entity indexes here
    for (int i = 0; i < numEntities; i++) {
        printf("Entity Index: %d\n", entityIndexes[i]);
    }
}

int main() {
    int numEntities = 0;
    
    // Dynamically allocate memory for the entity indexes
    int* entityIndexes = malloc(MAX_ENTITIES * sizeof(int));
    if (entityIndexes == NULL) {
        printf("Failed to allocate memory\n");
        return 1;
    }
    
    // Add entity indexes to the list
    for (int i = 0; i < 10; i++) {
        entityIndexes[numEntities++] = i; // Add entity index
    }
    
    // Pass the entity indexes to a function for processing
    processEntities(entityIndexes, numEntities);
    
    // Free the dynamically allocated memory
    free(entityIndexes);
    
    return 0;
}
