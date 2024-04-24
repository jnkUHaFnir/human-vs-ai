#include <stdio.h>
#include <stdlib.h>

int main() {
    int maxEntities = 3000; // maximum number of entities
    int *indexArray = NULL;
    int numEntities = 0; // number of entities added to the list

    // Allocate memory for the index array
    indexArray = (int*)malloc(maxEntities * sizeof(int));
    
    // Check if memory allocation was successful
    if (indexArray == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    // Add entities to the index array
    for (int i = 0; i < maxEntities; i++) {
        indexArray[i] = i; // adding entity index
        numEntities++;
    }

    // Pass the index array to a function
    // functionToProcessIndexes(indexArray, numEntities);

    // Free memory allocated for the index array
    free(indexArray);

    return 0;
}
