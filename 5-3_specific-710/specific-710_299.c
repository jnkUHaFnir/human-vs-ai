#include <stdio.h>
#include <stdlib.h>

// Function to add an entity to the array
void addEntity(int** entityArray, int* numEntities, int entity) {
    // Increase the number of entities
    (*numEntities)++;
    
    // Reallocate memory for the array to accommodate the new entity
    *entityArray = (int*)realloc(*entityArray, sizeof(int) * (*numEntities));
    
    // Add the new entity to the array
    (*entityArray)[*numEntities - 1] = entity;
}

int main() {
    int* entityArray = NULL;
    int numEntities = 0;
    
    // Add entities to the array
    addEntity(&entityArray, &numEntities, 1);
    addEntity(&entityArray, &numEntities, 2);
    addEntity(&entityArray, &numEntities, 3);
    
    // Process the array
    for(int i = 0; i < numEntities; i++) {
        printf("%d\n", entityArray[i]);
    }
    
    // Free the memory allocated for the array
    free(entityArray);
    
    return 0;
}
