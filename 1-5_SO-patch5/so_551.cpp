    #include <new>
    #include <cstdlib>
    struct Allocator {
        void track(void* p, void* container);
        void release(void* p, void* container);
    };
    void* operator new (size_t size, const Allocator& alloc, void* container)
    {
        void* allocated_memory = std::malloc(size);
        if (!allocated_memory) {
            throw std::bad_alloc();
        }
        alloc.track(allocated_memory, container);
        return allocated_memory;
    }
    void operator delete(void* p, const Allocator& alloc, void* container)
    {
        alloc.release(p, container);
        std::free(p);
    }
    int main()
    {
        Allocator alloc;
        int* i = new (alloc, NULL) int;
        ::operator delete(i, alloc, NULL);
    }