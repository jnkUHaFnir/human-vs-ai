#include <stdlib.h>
#include <string.h>

void *aligned_malloc(size_t size, size_t align) {
    void *mem = NULL;
    #if defined(_MSC_VER)
        mem = _aligned_malloc(size, align);
    #elif defined(__GNUC__)
        if (posix_memalign(&mem, align, size) != 0) {
            mem = NULL;
        }
    #endif

    return mem;
}

void aligned_free(void *mem) {
    #if defined(_MSC_VER)
        _aligned_free(mem);
    #elif defined(__GNUC__)
       free(mem);
    #endif
}

void memset_16aligned(void *ptr, int value, size_t size) {
    memset(ptr, value, size);
}

int main() {
    void *mem = aligned_malloc(1024, 16);
    void *ptr = mem;

    memset_16aligned(ptr, 0, 1024);

    aligned_free(mem);

    return 0;
}
