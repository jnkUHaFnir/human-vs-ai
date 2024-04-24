#include <stdio.h>
#include <stdlib.h>

void processEntities(int *entityIndexes, int numEntities) {
    // Process the entity indexes here
    for (int i = 0; i < numEntities; i++) {
        printf("Entity Index: %d\n", entityIndexes[i]);
    }
}

void addEntityToList(int **entityList, int *numEntities, int newEntityIndex) {
    (*numEntities)++;
    *entityList = (int*)realloc(*entityList, (*numEntities) * sizeof(int));
    if (*entityList == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    (*entityList)[(*numEntities) - 1] = newEntityIndex;
}

int main() {
    int *entityIndexes = NULL;
    int numEntities = 0;

    // Add entities to the list
    addEntityToList(&entityIndexes, &numEntities, 5);
    addEntityToList(&entityIndexes, &numEntities, 10);
    addEntityToList(&entityIndexes, &numEntities, 15);

    // Process the entities
    processEntities(entityIndexes, numEntities);

    // Free the allocated memory
    free(entityIndexes);

    return 0;
}
