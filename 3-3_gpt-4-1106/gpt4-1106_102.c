void *mem = malloc(1024 + 15); // Allocate extra bytes for manual alignment
if (mem == NULL) {
    // Handle allocation failure
}

// Calculate the aligned memory address. We add 15 to the address and then
// mask off the lower 4 bits to achieve the alignment.
ptr = (void *)(((uintptr_t)mem + 15) & ~(uintptr_t)0x0F);

// It would be a good idea to save the original pointer for the free call later.
void *original_mem = mem;
// answer b) here    

free(original_mem); // Free the original allocated memory
// answer a)
ptr = aligned_alloc(16, 1024); // Allocate 1024 bytes aligned to a 16-byte boundary
if (ptr == NULL) {
    // Handle allocation failure
}

memset_16aligned(ptr, 0, 1024); // Use the aligned memory

// answer b)
free(ptr); // Free the aligned memory
