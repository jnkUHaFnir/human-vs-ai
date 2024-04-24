#include <stdio.h>
#include <stdlib.h>

void processEntities(int* indexes, int numEntities) {
    // Processing entities using the indexes
    for (int i = 0; i < numEntities; i++) {
        printf("Entity Index: %d\n", indexes[i]);
    }
}

int main() {
    int numEntities = 5; // For demonstration purposes, you can set this dynamically based on your needs

    // Dynamically allocate memory for the array of indexes
    int *indexes = (int*)malloc(numEntities * sizeof(int));

    if (indexes == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Populate the array with entity indexes (for demonstration)
    for (int i = 0; i < numEntities; i++) {
        indexes[i] = i * 10; // Just an example, you can set the values based on your requirements
    }

    // Pass the array of indexes to a function for processing
    processEntities(indexes, numEntities);

    // Free the dynamically allocated memory
    free(indexes);

    return 0;
}
