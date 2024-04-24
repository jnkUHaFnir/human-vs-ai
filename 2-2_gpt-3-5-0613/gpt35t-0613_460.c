#include <stdio.h>
#include <stdlib.h>

void *memset_16aligned(void *ptr, int value, size_t num);

int main() {
    void *mem;
    void *ptr;

    // answer a) here
    if (posix_memalign(&mem, 16, 1024) != 0) {
        fprintf(stderr, "Failed to allocate aligned memory\n");
        return 1;
    }

    ptr = mem;

    memset_16aligned(ptr, 0, 1024);

    // answer b) here
    free(mem);

    return 0;
}
