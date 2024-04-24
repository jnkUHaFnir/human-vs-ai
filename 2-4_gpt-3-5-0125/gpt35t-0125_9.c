void *mem;
void *ptr;

// Allocate memory with extra space for alignment
mem = malloc(1024 + 16);

// Calculate the aligned address
uintptr_t addr = (uintptr_t)mem;
uintptr_t mask = 15; // 16 byte alignment
uintptr_t misalignment = addr & mask;
uintptr_t adjustment = (misalignment != 0) ? (16 - misalignment) : 0;
uintptr_t aligned_addr = addr + adjustment;

// Set ptr to the aligned address
ptr = (void *)aligned_addr;

// After memset_16aligned
free(mem);
