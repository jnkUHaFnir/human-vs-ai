static inline void *load_next(void **ptr, size_t offset) {
    char *byte_ptr = (char *)ptr;
    byte_ptr += offset;
    void *next_ptr;
    asm volatile("mov (%1), %0" : "=r" (next_ptr) : "r" (byte_ptr));
    return next_ptr;
}
