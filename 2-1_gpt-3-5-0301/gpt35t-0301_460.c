void *mem;
void *ptr;

if (posix_memalign(&mem, 16, 1024 + 16) == 0) { // allocate 16 extra bytes
    ptr = (void *)(((uintptr_t)mem + 15) & ~15); // 16-byte alignment
    size_t offset = ptr - mem; // offset for later free
    memset_16aligned(ptr, 0, 1024);
    free((char *)mem - offset); // free original memory address
}
free((char *)mem - offset);
