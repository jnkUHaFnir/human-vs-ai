float fileArr[currentSz];
#include <stdlib.h> // For malloc and free

// ...

float *fileArr = (float *) malloc(currentSz * sizeof(float));
if (fileArr == NULL) {
    // Handle memory allocation error
    exit(EXIT_FAILURE);
}

// ... use fileArr as before ...

// Don't forget to free the dynamically allocated memory
free(fileArr);
