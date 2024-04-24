int* entityIndexes = NULL;  // Pointer to array of indexes
int numEntities = 0;        // Counter for the number of entities

// Function to add an entity index to the list
void addEntity(int index) {
    numEntities++;
    // Resize the array to accommodate the new index
    entityIndexes = realloc(entityIndexes, sizeof(int) * numEntities);
    // Add the new index to the array
    entityIndexes[numEntities - 1] = index;
}

// Function to process the entity index list
void processEntities() {
    for (int i = 0; i < numEntities; i++) {
        // Process each entity index here
    }
    // Free the dynamically allocated memory after use
    free(entityIndexes);
}

int main() {
    // Add entity indexes to the list...
    addEntity(10);
    addEntity(20);
    addEntity(30);
    
    // Process the entity index list
    processEntities();
    
    return 0;
}
