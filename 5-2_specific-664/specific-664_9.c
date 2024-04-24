#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *memalign_16(size_t size) {
    void *ptr = malloc(size + 16 + sizeof(void*));
    if (ptr) {
        void *aligned_ptr = (void*)(((size_t)(ptr) + 16 + sizeof(void*)) & ~(size_t)(15));
        void **real_ptr = (void**)((char*)aligned_ptr - sizeof(void*));
        *real_ptr = ptr;
        return aligned_ptr;
    }
    return NULL;
}

void free_memaligned(void *ptr) {
    if (ptr) {
        void **real_ptr = (void**)((char*)ptr - sizeof(void*));
        free(*real_ptr);
    }
}

void memset_16aligned(void* ptr, int value, size_t size) {
    memset(ptr, value, size);
}

int main() {
    void *mem;
    void *ptr;

    // Allocate 1024 bytes aligned to 16 bytes
    ptr = memalign_16(1024);
    
    if (ptr == NULL) {
        printf("Failed to allocate memory aligned to 16 bytes\n");
        return 1;
    }

    memset_16aligned(ptr, 0, 1024);

    // Free the memory
    free_memaligned(ptr);

    return 0;
}
