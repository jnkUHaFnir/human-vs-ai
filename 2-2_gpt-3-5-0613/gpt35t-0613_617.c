#include <stdlib.h>

void readFromFile() {
    // ...
    while (currentSz <= maxSz) {
        // Dynamically allocate memory for the array
        float* fileArr = malloc(currentSz * sizeof(float));
        if (fileArr == NULL) {
            // Handle memory allocation failure
            printf("Failed to allocate memory for fileArr\n");
            exit(1);
        }

        // Rest of your code ...

        // After you are done with the array, free the allocated memory
        free(fileArr);

        // ...
    }
}
