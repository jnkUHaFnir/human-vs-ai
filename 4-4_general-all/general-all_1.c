#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr; // Uninitialized pointer

    // Allocate memory
    ptr = (int*)malloc(sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Do something with ptr (not relevant for the example)

    // Free memory
    free(ptr);
    ptr = NULL; // Set pointer to NULL after freeing

    return 0;
}
