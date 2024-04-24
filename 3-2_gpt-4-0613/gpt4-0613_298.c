int* entityArray = NULL;    // this will be our dynamic array
int entityCount = 0;        // this will keep track of the number of entities in the array

// given a new entity id, add it to the array
void addEntity(int entityId) {
    // "reallocate" the array to accommodate an extra entity. 
    // reallocation involves creating a new chunk of memory, copying over the old data 
    // and deallocating the old memory.
    int* newEntityArray = (int*) realloc(entityArray, (entityCount + 1) * sizeof(int));
    if(newEntityArray == NULL) {
        // TODO: handle memory allocation error
    } else {
        // if reallocation was successful, our entity array now points to the newly-allocated memory...
        entityArray = newEntityArray;
        // ...and we can add our new entity
        entityArray[entityCount] = entityId;
        // don't forget to increment the entity count
        entityCount++;
    }
}

// when you're done with the array, you can deallocate the memory to avoid leaks
void cleanupEntities() {
    free(entityArray);
    entityArray = NULL; // It's good practice to set your pointer to NULL after freeing it.
    entityCount = 0;
}
