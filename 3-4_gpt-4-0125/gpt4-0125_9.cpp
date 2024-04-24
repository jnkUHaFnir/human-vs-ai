#include <stdlib.h>
#include <stdalign.h>

// For C11, you can use aligned_alloc
mem = aligned_alloc(16, 1024);
ptr = mem; // ptr is now 16-byte aligned.
#include <cstdlib>

// In C++, you can use std::aligned_alloc (C++17) or posix_memalign (C++11 for POSIX systems)
mem = std::aligned_alloc(16, 1024);
ptr = mem; // ptr is now 16-byte aligned.
mem = malloc(1024 + 15); // Allocate extra memory so we can adjust alignment.
if(mem != NULL) {
    // Adjust `ptr` to the next 16-byte boundary if necessary.
    ptr = (void*)(((size_t)mem + 15) & ~((size_t)15));
}
free(mem); // Always free the original pointer, not `ptr`.
