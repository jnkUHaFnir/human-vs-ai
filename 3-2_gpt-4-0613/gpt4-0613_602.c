void* emalloc(size_t n) {
    void* p = malloc(n);
    if (p == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
