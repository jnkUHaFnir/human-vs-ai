void *mem;
void *ptr;

if (posix_memalign(&mem, 16, 1024) != 0) {
    // handle allocation error
} else {
    ptr = mem;
}
free(ptr);
