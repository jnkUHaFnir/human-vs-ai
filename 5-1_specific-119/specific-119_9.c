void *mem;
void *ptr;

// Allocate 1024 bytes aligned to a 16 byte boundary
#ifdef _WIN32
ptr = _aligned_malloc(1024, 16);
#else
posix_memalign(&ptr, 16, 1024);
#endif

if (ptr == NULL) {
    // Handle allocation failure
}
// Free the memory after memset_16aligned has executed
#ifdef _WIN32
_aligned_free(ptr);
#else
free(ptr);
#endif
``` 

Remember to include the necessary headers (`#include <stdlib.h>` for `posix_memalign` and `#include <malloc.h>` for `_aligned_malloc` and `_aligned_free`).
