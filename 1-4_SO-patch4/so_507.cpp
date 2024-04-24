    // C++17
    // The allocator backend.
    // Intended to be used by type-aware allocator(standard allocator template).
    #include <new>     // For std::bad_alloc.
    #include <cstdlib> // For C heap management API.
    #include <cstddef> // For std::size_t, std::max_align_t.
    #include <cassert> // For assert.
    #define NDEBUG
      
    namespace linux {
    #include <sys/mman.h> // For mmap, mremap, munmap.
    #include <errno.h>    // For errno.
    auto get_errno() noexcept {
        return errno;
    }
    }
    
    // class mrealloc are usefull for allocating small space for
    // std::vector.
    //
    // Can prevent copy of data and memory fragmentation if there's enough
    // continous memory at the original place.
    //
    // But when it fails to expand the original allocation,
    // the position of data may change and the copy ctor won't be called.
    // So, don't rely on the side-effect of copy ctor.
    struct mrealloc {
        using value_type = char;
     
        auto allocate(std::size_t len) {
            if (auto ret = std::malloc(len))
                return ret;
            else
                throw std::bad_alloc();
        }
        auto reallocate(void *old_ptr, std::size_t len) {
            if (auto ret = std::realloc(old_ptr, len))
                return ret;
            else 
                throw std::bad_alloc();
        }
        void deallocate(void *ptr) {
            std::free(ptr);
        }
        // Zero-initialize the memory.
        constexpr void construct(value_type *p) const noexcept { *p = 0; }
    };
    
    // class mmaprealloc is suitable for large memory use.
    //
    // It will be usefull for situation that std::vector can grow to a huge
    // size.
    //
    // User can call reserve without worrying wasting a lot of memory.
    //
    // It can prevent data copy and memory fragmentation at any time.
    //
    // But when it fails to expand the original allocation,
    // the position of data may change and the copy ctor won't be called.
    // So, don't rely on the side-effect of copy ctor.  
      
    struct mmaprealloc {
        using value_type = char;
    
        // Func allocate and reallcoate are separated
        // to enable overload from derived class.
    
        void* allocate(std::size_t len) const 
        {
            return allocate_impl(len, MAP_PRIVATE | MAP_ANONYMOUS);
        }   
        void* reallocate(void *old_ptr, std::size_t old_len) const 
        {
            return reallocate_impl(old_ptr, old_len, MREMAP_MAYMOVE);
        }    
        void deallocate(void *_ptr) const noexcept 
        {
            auto [ptr, len] = get_raw_ptr(_ptr);
            assert(linux::munmap(ptr, len) == 0);
        }
    
        // Construct does nothing here because the returned memory is already
        // zero-initialized.
        constexpr void construct(value_type*) const noexcept {}
    
      protected:
        void* allocate_impl(std::size_t _len, int flags) const 
        {
            auto len = get_proper_size(_len);
    
            if (auto ret = linux::mmap(nullptr, len, PROT_READ | PROT_WRITE, flags, -1, 0))
                return get_usr_oriented_ptr(ret, len);
            else
                fail(EAGAIN | ENOMEM);
        }              
        void* reallocate_impl(void *_old_ptr, std::size_t _len, int flags) const 
        {
            auto [old_ptr, old_len] = get_raw_ptr(_old_ptr);
            auto len = get_proper_size(_len);
    
            if (auto ret = linux::mremap(old_ptr, old_len, len, flags))
                return get_usr_oriented_ptr(ret, len);
            else
                fail(EAGAIN | ENOMEM);
        }
        
        static inline constexpr const std::size_t magic_num = 4096 - 1;
        static inline auto get_proper_size(std::size_t len) noexcept -> std::size_t {
            return round_to_pagesize(len + sizeof(std::max_align_t));
        }
        static inline auto round_to_pagesize(std::size_t len) noexcept -> std::size_t {
            return (len + magic_num) & ~magic_num;
        }
    
        static inline auto get_usr_oriented_ptr(void *_ptr, std::size_t len) noexcept -> void*
        {
            auto ptr = static_cast<std::size_t*>(_ptr);
            *ptr = len;
            return static_cast<void*>(ptr + sizeof(std::max_align_t) / sizeof(std::size_t));
        }
        static inline auto get_raw_ptr(void *ptr) noexcept -> std::pair<void*, std::size_t<
        {
            auto old_ptr = (std::size_t*) ((std::size_t) ptr & ~magic_num);
            auto old_len = *old_ptr;
            return std::pair(old_ptr, old_len);
        }
        static inline void fail(int assert_val)
        {
            auto _errno = linux::get_errno();
            assert(_errno == assert_val);
            throw std::bad_alloc();
        }
    };