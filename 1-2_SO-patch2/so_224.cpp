    #include <new>
    #include <cstdlib>
    struct Allocator {
        void track(void* p, const void* container) const;
        void release(void* p, const void* container) const;
    };
    void* operator new (size_t size, const Allocator& alloc, const void* container)
    {
        void* allocated_memory = std::malloc(size);
        if (!allocated_memory) {
            throw std::bad_alloc();
        }
        alloc.track(allocated_memory, container);
        return allocated_memory;
    }
    void deallocate(void* p, const Allocator& alloc, const void* container)
    {
        alloc.release(p, container);
        std::free(p);
    }
    int main()
    {
        Allocator alloc;
        int* i = new (alloc, NULL) int;
        deallocate(i, alloc, NULL);
    }