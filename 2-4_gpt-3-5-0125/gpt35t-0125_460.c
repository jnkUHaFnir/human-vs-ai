void *mem;
void *ptr;

posix_memalign(&mem, 16, 1024);
ptr = mem;
free(mem);
``` 

This will properly allocate and align the memory for the memset_16aligned function, and then free it after the function has executed.
