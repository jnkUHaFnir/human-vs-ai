{
    void *mem;
    void *ptr;

    // answer a) here
    mem = malloc(1024 + 15);             // allocates some memory
    ptr = (void*)((uintptr_t)(mem+15) & ~(uintptr_t)0x0F);   // align to nearest upper boundary

    memset_16aligned(ptr, 0, 1024);

    // answer b) here    
    free(mem);                          // frees the memory
}
