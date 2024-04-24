#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = NULL;
    size_t size = 100;

    ptr = (int*)malloc(size * sizeof(int));
    
    if (ptr == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    
    // Use allocated memory
    
    free(ptr); // Don't forget to free allocated memory
    
    return 0;
}
