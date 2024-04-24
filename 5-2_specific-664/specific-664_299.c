#include <stdio.h>

#define MAX_ENTITIES 3000

void processEntities(const int *indexes, int count) {
    // Process the entities using the indexes
    for (int i = 0; i < count; i++) {
        printf("Processing entity with index: %d\n", indexes[i]);
    }
}

void localProcessingFunction() {
    int entityIndexes[MAX_ENTITIES]; // Stack-allocated array for indexes
    int entityCount = 0;

    // Add some entities to the list
    for (int i = 0; i < 10; i++) {
        entityIndexes[entityCount++] = i; // Assuming here you add indexes dynamically
    }

    // Pass the array of indexes to a function for processing
    processEntities(entityIndexes, entityCount);
}

int main() {
    localProcessingFunction();
    
    // The entityIndexes array is only valid within the localProcessingFunction scope
    // and will be automatically deallocated when the function exits
    
    return 0;
}
