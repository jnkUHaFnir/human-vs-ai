#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main() {
    int* array;
    array = (int*)safe_malloc(MAX_SIZE * sizeof(int));

    // Use the allocated memory as needed
    for (int i = 0; i < MAX_SIZE; i++) {
        array[i] = i;
    }

    // Don't forget to free the allocated memory when done
    free(array);

    return 0;
}
