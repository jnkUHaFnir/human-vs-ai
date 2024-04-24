void *mem;
void *ptr;
int ret = posix_memalign(&mem, 16, 1024);
if (ret != 0) {
    // handle error
} else {
    ptr = mem;
}
free(mem);
