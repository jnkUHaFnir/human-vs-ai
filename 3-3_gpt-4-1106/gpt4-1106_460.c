#include <stdlib.h> // Required for malloc() and free()
#include <stdint.h> // Required for uintptr_t

// ...

// Allocate memory with enough space for the alignment padding and a pointer
mem = malloc(1024 + 16 + sizeof(void*));

if(mem != NULL)
{
   // Calculate the aligned memory address by rounding up to the nearest multiple of 16
   ptr = (void*)(((uintptr_t)mem + 16 + sizeof(void*) - 1) & ~(uintptr_t)(16 - 1));

   // Store the original pointer just before the aligned address
   *((void**)((uintptr_t)ptr - sizeof(void*))) = mem;
}

// Now ptr is a 16-byte aligned pointer to a block of 1024 bytes
// ...

// Retrieve the original pointer from just before the aligned address
void *original_ptr = *((void**)((uintptr_t)ptr - sizeof(void*)));

// Free the original unaligned block of memory
free(original_ptr);

// ...
// ...

// Allocate 1024 bytes of memory aligned to a 16-byte boundary
ptr = aligned_alloc(16, 1024);

// Use ptr as needed; it is guaranteed to be 16-byte aligned

// ...

// When done, free the memory
free(ptr);

// ...
