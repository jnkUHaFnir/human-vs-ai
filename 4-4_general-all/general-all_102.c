#include <stdlib.h>
#include <string.h>

void *memset_16aligned(void *s, int c, size_t n) {
    return memset(s, c, n);
}

int main() {
    void *mem;
    void *ptr;

    // Allocate 1024 bytes of memory aligned to a 16-byte boundary
    if (posix_memalign(&mem, 16, 1024) != 0) {
        // Handle allocation failure
        return 1;
    }

    ptr = mem;

    memset_16aligned(ptr, 0, 1024);

    // Free the aligned memory
    free(mem);

    return 0;
}
