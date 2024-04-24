#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* allocate_16aligned(size_t size) {
    void* mem = malloc(size + 16 + sizeof(void*));
    if (mem == NULL) {
        return NULL;
    }

    void** ptr = (void**)((size_t)(mem + 16 + sizeof(void*)) & ~0xF);
    ptr[-1] = mem;
    return ptr;
}

void deallocate_16aligned(void* ptr) {
    void* mem = ((void**)ptr)[-1];
    free(mem);
}

void memset_16aligned(void* ptr, int value, size_t num) {
    memset(ptr, value, num);
}

int main() {
    void* mem = allocate_16aligned(1024);
    if (mem == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    memset_16aligned(mem, 0, 1024);

    deallocate_16aligned(mem);

    return 0;
}
