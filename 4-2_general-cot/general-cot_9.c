#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memset_16aligned(void *ptr, int value, size_t size) {
    memset(ptr, value, size);
}

int main() {
    void *mem;
    void *ptr;
    
    // Allocate memory with posix_memalign
    if (posix_memalign(&mem, 16, 1024) != 0) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    ptr = mem; // Assigning mem to ptr for further processing

    memset_16aligned(ptr, 0, 1024);

    // Free the allocated memory
    free(mem);

    return 0;
}
