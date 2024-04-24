#include <stdlib.h> // for posix_memalign

void *mem;
void *ptr;

// Allocate 1024 bytes of memory and align it to a 16 byte boundary
if (posix_memalign(&mem, 16, 1024) != 0) {
    // Handle allocation error
    // For illustration purposes, we exit the program here
    exit(EXIT_FAILURE);
}

ptr = mem; // Assign the aligned pointer to ptr

// Use ptr for subsequent operations

// Free the memory after memset_16aligned has executed
free(ptr);
