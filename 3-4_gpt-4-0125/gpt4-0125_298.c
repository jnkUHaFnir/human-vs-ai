int *entityIndexes = (int*)malloc(n * sizeof(int));
if (entityIndexes == NULL) {
    // Handle allocation failure (e.g., due to not enough memory)
}
int *entityIndexes = (int*)calloc(n, sizeof(int));
if (entityIndexes == NULL) {
    // Handle allocation failure
}
entityIndexes = (int*)realloc(entityIndexes, newSize * sizeof(int));
if (entityIndexes == NULL) {
    // Handle reallocation failure
}
free(entityIndexes);
void processEntities(size_t numberOfEntities) {
    int *entityIndexes = (int*)malloc(numberOfEntities * sizeof(int));
    if (entityIndexes == NULL) {
        // Handle allocation failure
        return;
    }

    // Assuming you have a way to fill this array
    for (size_t i = 0; i < numberOfEntities; ++i) {
        entityIndexes[i] =  // assign corresponding value here;
    }

    // Pass the array to other functions as needed
    someOtherFunction(entityIndexes, numberOfEntities);

    // Free the allocated memory before returning from the function
    free(entityIndexes);
}
