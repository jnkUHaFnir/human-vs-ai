#include <stdlib.h>   /* for malloc and free */

void readFromFile() {
    // ... (as before)

    while (currentSz <= maxSz) {
        // Dynamically allocate memory
        float* fileArr = (float*)malloc(currentSz * sizeof(float));
        if (fileArr == NULL) {
            /* handle error condition here,
               e.g., abort */
        }
        // ... (rest of your code)

        // Free memory when you're done with it
        free(fileArr);

        currentSz += 20000;
    }
}
