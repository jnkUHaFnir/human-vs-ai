#include <stdio.h>
#include <stdlib.h>

void processEntities(int* entityIndexes, int numEntities) {
    // Process the entity indexes here
    // ...
}

void mainProcessingFunction() {
    int maxEntities = 3000;
    int* entityIndexes = (int*)malloc(maxEntities * sizeof(int));
    if (entityIndexes == NULL) {
        // Handle error for memory allocation
        exit(1);
    }
    
    int numEntities = 0;
    
    // Add entity indexes to the array
    entityIndexes[numEntities++] = 123;
    entityIndexes[numEntities++] = 456;
    // ...

    // Pass the array of indexes to the processing function
    processEntities(entityIndexes, numEntities);

    // Free the allocated memory when done
    free(entityIndexes);
}
