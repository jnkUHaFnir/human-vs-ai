#include <stdio.h>
#include <stdlib.h>

int main() {
    int maxEntities = 3000; // maximum game entities
    int *entityIndexes = NULL;
    int entitiesAdded = 0;

    // Dynamically allocate memory for the initial size
    entityIndexes = (int*)malloc(maxEntities * sizeof(int));

    // Check if memory allocation was successful
    if (entityIndexes == NULL) {
        printf("Memory allocation failed. Exiting...\n");
        return 1;
    }

    // Add an entity to the list
    entityIndexes[entitiesAdded++] = 10; // Add entity index 10

    // Add more entities... (realloc if needed)

    // Clean up - free the allocated memory
    free(entityIndexes);

    return 0;
}
