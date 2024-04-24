void *mem;
void *ptr;

// Allocate memory and align it to a 16 byte boundary
if (posix_memalign(&mem, 16, 1024) != 0) {
    // Handle allocation error
    perror("posix_memalign");
    exit(EXIT_FAILURE);
}

ptr = mem;

// Now ptr is a 16-byte aligned pointer pointing to a block of memory of size 1024 bytes

// Free the allocated memory
free(mem);
