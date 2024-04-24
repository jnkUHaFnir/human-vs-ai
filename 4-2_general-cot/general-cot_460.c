#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void memset_16aligned(void *ptr, int value, size_t num_bytes) {
    memset(ptr, value, num_bytes);
}

int main() {
    void *mem;
    void *ptr;

    if (posix_memalign(&mem, 16, 1024) != 0) {
        perror("posix_memalign failed");
        return 1;
    }

    ptr = mem;

    memset_16aligned(ptr, 0, 1024);

    // Use the memory allocated and aligned

    free(mem); // answer b) Free the allocated memory

    return 0;
}
