    void *mem = malloc(1024+15+sizeof(void*));
    ASSERT(mem);
    void *ptr = ((char*)mem+sizeof(void*)+15) & ~ (size_t)0x0F;
    ((void**)ptr)[-1] = mem;