#include <stdlib.h>
#include <string.h>

void *mem;
void *ptr;
size_t size = 1024;

// Allocate memory and align it to a 16-byte boundary
if (posix_memalign(&mem, 16, size) != 0) {
    // Handle allocation failure
    return 1;
}

// Set ptr to aligned address
ptr = mem;

// Use ptr for memset_16aligned or any other operation

// Free allocated memory after use
free(mem);
