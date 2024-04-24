#include <stdio.h>
#include <stdlib.h>

int main() {
    int initialSize = 10; // Initial capacity
    int *indexes = malloc(initialSize * sizeof(*indexes)); // Allocate initial memory
    if (indexes == NULL) {
        // Handle memory allocation failure
        perror("Failed to allocate memory for indexes");
        return EXIT_FAILURE;
    }
    
    int currentSize = initialSize;
    int entitiesCount = 0; // Keep track of the number of entities
    
    // Simulation of entity addition
    for (int i = 0; i < 3000; i++) { // Example of adding 3000 entities
        // Resize if full
        if (entitiesCount == currentSize) {
            currentSize *= 2; // Double the size
            int *temp = realloc(indexes, currentSize * sizeof(*indexes));
            if (temp == NULL) {
                // Handle memory allocation failure
                free(indexes);
                perror("Failed to reallocate memory for indexes");
                return EXIT_FAILURE;
            }
            indexes = temp;
        }
        
        // Add entity index to the array
        indexes[entitiesCount++] = i;
    }
    
    // Do something with indexes...
    
    // Don't forget to free the memory once done
    free(indexes);
    
    return 0;
}
