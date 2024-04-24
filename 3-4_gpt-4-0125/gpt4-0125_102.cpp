#include <stdlib.h>

void my_function() {
    void *ptr;

    // Allocate memory, aligned to a 16-byte boundary
    if (posix_memalign(&ptr, 16, 1024) != 0) {
        // handle error, allocation failed
        return;
    }

    memset_16aligned(ptr, 0, 1024);

    // Free the memory
    free(ptr);
}
#include <malloc.h>

void my_function() {
    void *ptr;

    // Allocate memory, aligned to a 16-byte boundary
    ptr = _aligned_malloc(1024, 16);
    if (ptr == NULL) {
        // handle error, allocation failed
        return;
    }

    memset_16aligned(ptr, 0, 1024);

    // Free the memory
    _aligned_free(ptr);
}
#include <cstdlib>

void my_function() {
    void* ptr;

    // Allocate memory, aligned to a 16-byte boundary
    ptr = std::aligned_alloc(16, 1024);
    if (ptr == nullptr) {
        // handle error, allocation failed
        return;
    }

    memset_16aligned(ptr, 0, 1024);

    // Free the memory
    std::free(ptr);
}
