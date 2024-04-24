#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void* allocate_aligned(size_t size, size_t alignment) {
    void *ptr = NULL;
    if (posix_memalign(&ptr, alignment, size) != 0) {
        perror("posix_memalign failed");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

int main() {
    void *mem;
    void *ptr;

    mem = allocate_aligned(1024, 16);

    // Assuming that memset_16aligned function is implemented separately
    memset_16aligned(ptr, 0, 1024);

    // Code to use the allocated memory

    free(mem); // Free the allocated memory

    return 0;
}
