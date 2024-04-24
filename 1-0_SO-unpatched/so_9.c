    /* allocate a buffer with room to add 0-15 bytes to ensure 16-alignment */
    void *mem = malloc(1024+15);
    ASSERT(mem); // some kind of error-handling code
    /* round up to multiple of 16: add 15 and then round down by masking */
    void *ptr = ((char*)mem+15) & ~ (size_t)0x0F;