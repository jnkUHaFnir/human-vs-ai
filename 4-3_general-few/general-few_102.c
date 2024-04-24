void *mem;
void *ptr;

// Allocate memory aligned to 16 bytes
if (posix_memalign(&mem, 16, 1024) != 0) {
    // Handle allocation error
    return 1;
}

ptr = mem;

memset_16aligned(ptr, 0, 1024);

// Your code using ptr goes here

// Free the allocated memory
free(mem);
