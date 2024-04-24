#include <stdio.h>
#include <stdlib.h>

int main() {
    int* entityIndexes = NULL;
    int numEntities = 0;
    
    // Simulating adding entities to the array
    for (int i = 0; i < 3000; i++) {
        int entityID = i; // Example entity ID
        
        // Dynamically allocate memory for the new index
        entityIndexes = (int*)realloc(entityIndexes, (numEntities + 1) * sizeof(int));
        
        // Check if memory allocation was successful
        if (entityIndexes == NULL) {
            // Handle allocation failure
            perror("Memory allocation failed");
            // Clean up existing memory before exiting
            free(entityIndexes);
            return 1;
        }
        
        // Add the new entity index to the array
        entityIndexes[numEntities] = entityID;
        numEntities++;
    }
    
    // Process the list of entity indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Entity index: %d\n", entityIndexes[i]);
    }
    
    // Clean up the dynamically allocated memory
    free(entityIndexes);

    return 0;
}
