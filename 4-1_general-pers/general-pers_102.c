#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to handle memory alignment
void *align_malloc(size_t size, size_t alignment) {
    void *ptr = NULL;
    if (posix_memalign(&ptr, alignment, size) != 0) {
        perror("posix_memalign");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

// Custom memset function for 16-byte aligned memory
void memset_16aligned(void *ptr, int value, size_t size) {
    memset(ptr, value, size);
    // Additional specific operations for 16-byte alignment if needed
}

int main() {
    void *mem;
    void *ptr;
    
    // Allocating 1024 bytes of memory aligned to a 16-byte boundary
    mem = align_malloc(1024, 16);
    ptr = mem;

    // Using the custom memset function for 16-byte aligned memory
    memset_16aligned(ptr, 0, 1024);

    // Freeing the allocated memory
    free(mem);

    return 0;
}
