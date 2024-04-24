#include <stdio.h>
#include <stdlib.h>

// Function to add an entity index to the list
void addEntityIndex(int **list, int *count, int index) {
    // Increase count
    (*count)++;
    
    // Reallocate memory to accommodate the new index
    *list = realloc(*list, (*count) * sizeof(int));
    if (*list == NULL) {
        // Handle allocation failure
        printf("Memory allocation failed\n");
        exit(1);
    }
    
    // Add the new index to the list
    (*list)[(*count) - 1] = index;
}

// Function to process the list of entity indexes
void processEntityIndexes(int *list, int count) {
    printf("Processing entity indexes:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int *entityList = NULL;
    int entityCount = 0;

    // Adding entity indexes
    addEntityIndex(&entityList, &entityCount, 1);
    addEntityIndex(&entityList, &entityCount, 2);
    addEntityIndex(&entityList, &entityCount, 3);

    // Processing entity indexes
    processEntityIndexes(entityList, entityCount);

    // Free dynamically allocated memory
    free(entityList);

    return 0;
}
