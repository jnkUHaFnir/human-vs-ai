#include <stdio.h>
#include <stdlib.h>

// Function to add an entity index to the list
void addEntityToList(int** entityList, int* numOfEntities, int entityIndex) {
    // Increase the size of the list by reallocating memory
    *entityList = (int*)realloc(*entityList, (*numOfEntities + 1) * sizeof(int));
    
    // Check if memory reallocation was successful
    if (*entityList == NULL) {
        printf("Memory allocation failed. Exiting...");
        exit(1);
    }
    
    // Add the new entity index to the list
    (*entityList)[*numOfEntities] = entityIndex;
    (*numOfEntities)++;
}

// Function to process the list of entity indexes
void processEntityList(int* entityList, int numOfEntities) {
    // Process each entity index in the list
    for (int i = 0; i < numOfEntities; i++) {
        printf("Entity Index: %d\n", entityList[i]);
    }
}

int main() {
    int* entityList = NULL;  // Pointer to store the entity indexes
    int numOfEntities = 0;   // Number of entities in the list
    
    // Add some entity indexes to the list
    addEntityToList(&entityList, &numOfEntities, 100);
    addEntityToList(&entityList, &numOfEntities, 200);
    addEntityToList(&entityList, &numOfEntities, 300);
    
    // Process the list of entity indexes
    processEntityList(entityList, numOfEntities);
    
    // Free the dynamically allocated memory
    free(entityList);
    
    return 0;
}
