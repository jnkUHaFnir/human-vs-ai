#include <stdlib.h>

void *mem;
void *ptr;

// Allocate memory with an extra 16 bytes to ensure alignment
mem = malloc(1024 + 16);

// Calculate the aligned pointer by masking the lower 4 bits to ensure it's aligned to 16 bytes
ptr = (void *)(((uintptr_t)mem + 16) & ~15);
free(mem);
``` 

Make sure to include the necessary headers and typecast the pointers accordingly for the code to compile and run correctly.
