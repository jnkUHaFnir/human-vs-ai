#include <stdlib.h>

int numberOfEntities = getNumberOfEntities(); // Somehow determine the actual number needed.
int* entityIndices = (int*)malloc(numberOfEntities * sizeof(int));
if (entityIndices == NULL) {
    // Handle memory allocation failure
}
for(int i = 0; i < numberOfEntities; i++) {
    entityIndices[i] = i; // Or however you determine the index
}
void processEntities(int* entities, int size) {
    for(int i = 0; i < size; i++) {
        // Process entity with index entities[i]
    }
}

// Calling the function
processEntities(entityIndices, numberOfEntities);
free(entityIndices);
