#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTITIES 3000

void processEntities(int* entityIndexes, int numEntities) {
    // Process the entities here
    for (int i = 0; i < numEntities; i++) {
        printf("Processing entity at index %d\n", entityIndexes[i]);
    }
}

int main() {
    int* entityIndexes = (int*)malloc(sizeof(int) * MAX_ENTITIES);
    if (entityIndexes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    int numEntities = 0;

    // Add entities to the list
    for (int i = 0; i < 10; i++) {
        entityIndexes[numEntities++] = i; // Add entity index to the list
    }

    // Process the entities
    processEntities(entityIndexes, numEntities);

    // Free the dynamically allocated memory
    free(entityIndexes);

    return 0;
}
