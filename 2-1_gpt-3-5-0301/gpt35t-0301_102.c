// Allocate memory
mem = malloc(1024 + 16);

// Calculate the aligned pointer
uintptr_t misalignment = (uintptr_t)mem % 16;
uintptr_t adjustment = misalignment ? (16 - misalignment) : 0;
ptr = (char*)mem + adjustment;
free((char*)ptr - adjustment);
