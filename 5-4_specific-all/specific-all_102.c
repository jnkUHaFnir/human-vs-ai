#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memset_16aligned(void *ptr, int value, size_t num_bytes) {
    // Your memset_16aligned function implementation here
}

int main() {
    void *mem;
    void *ptr;

    // Allocate 1024 bytes of memory aligned to 16 bytes
    if (posix_memalign(&mem, 16, 1024) != 0) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }
    ptr = mem;

    // Call memset_16aligned function
    memset_16aligned(ptr, 0, 1024);

    // Free the memory
    free(mem);

    return 0;
}
