#define TRACK_MEMORY 1

#if TRACK_MEMORY
void* operator new(size_t size);
void operator delete(void* ptr) noexcept;
#endif

#ifdef TRACK_MEMORY
void* operator new(size_t size) {
    void* ptr = malloc(size);
    // record allocation in a map or other data structure
    return ptr;
}
 
void operator delete(void* ptr) noexcept {
    // remove allocation from map or data structure
    free(ptr);
}
#endif
