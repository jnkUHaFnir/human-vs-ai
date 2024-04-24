#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to memset with 16-byte alignment
void memset_16aligned(void *ptr, int value, size_t num_bytes) {
    memset(ptr, value, num_bytes);
}

int main() {
    void *mem;
    void *ptr;

    // Answer a) Allocate 1024 bytes of memory aligned to a 16-byte boundary
#if defined(_WIN32) || defined(_WIN64)
    ptr = _aligned_malloc(1024, 16);
#elif defined(__APPLE__) || defined(__linux__)
    if (posix_memalign(&ptr, 16, 1024) != 0) {
        fprintf(stderr, "Memory alignment failed.\n");
        return 1;
    }
#else
    // Handle other platforms as needed
#endif

    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Using memset_16aligned function
    memset_16aligned(ptr, 0, 1024);

    // Answer b) Free the memory
#if defined(_WIN32) || defined(_WIN64)
    _aligned_free(ptr);
#else
    free(ptr);
#endif

    return 0;
}
