void *mem;
void *ptr;

// Allocate memory and align to 16 bytes
if (posix_memalign(&mem, 16, 1024) != 0) {
    // Handle allocation error
    printf("Memory allocation error\n");
    exit(1);
}

ptr = mem;

memset_16aligned(ptr, 0, 1024);

// Use the memory for your operations

// Free the memory after use
free(mem);
