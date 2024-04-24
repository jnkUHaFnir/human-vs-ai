    void* operator new(size_t size) {
        // See Effective C++, Item 8 for an explanation.
        if (size == 0)
            size = 1;
    
        cerr << "Allocating " << size << " bytes of memory:";
    
        while (true) {
            void* ret = malloc(size);
    
            if (ret != 0) {
                cerr << " @ " << ret << endl;
                return ret;
            }
    
            // Retrieve and call new handler, if available.
            new_handler handler = set_new_handler(0);
            set_new_handler(handler);
    
            if (handler == 0)
                throw bad_alloc();
            else
                (*handler)();
        }
    }
    
    void operator delete(void* p) {
        cerr << "Freeing pointer @ " << p << "." << endl;
        free(p);
    }