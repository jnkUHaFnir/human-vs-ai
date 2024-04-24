#include <stdlib.h>
#include <string.h>

void *mem;
void *ptr;

// Allocate 1024 bytes of memory aligned to a 16-byte boundary
posix_memalign(&mem, 16, 1024);
ptr = mem;
// Free the allocated memory
free(mem);
