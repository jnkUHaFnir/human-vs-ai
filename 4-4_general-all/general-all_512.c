#include <stdio.h>
#include <stdlib.h>

void* safeMalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed for size %zu\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main() {
    // Example usage
    int* ptr = (int*)safeMalloc(10 * sizeof(int));
    
    // Use ptr as needed
    
    free(ptr); // Don't forget to free allocated memory when done
    
    return 0;
}
