    // C++17
    #include <new> 
    #include <memory>
    #include <cstdlib>
    #include <cstddef>
    #include <cassert> 
    #include <cstring>
    namespace glibc {
    #include <sys/mman.h>
    }
    
    #define likely(expr) builtin_expect(!!(expr), true)
    
    struct vector_mrealloc {
           using value_type = void;
    
           void *last_deallocated_ptr;
    
            ~vector_alloc() {
                    std::free(ptr);
             }
            auto allocate(std::size_t len) {
                   if (likely(last_deallocated_ptr))
                        return realloc(len);
                   else
                        return alloc(len);
             }
            void deallocate(void *ptr) {
                  last_deallocated_ptr = ptr;
            }
         protected:
            auto alloc(std::size_t len) {
                   if (auto ret = std::malloc(len))
                        return ret;
                   else
                        throw bad_alloc(__PRETTY_FUNCTION__);
            }
            auto realloc(std::size_t len) {
                  if (auto ret = std::realloc(last_deallocated_ptr, len))
                      return ret;
                 else 
                      throw bad_alloc(__PRETTY_FUNCTION__);
            }
    };
    
    struct vector_mmaprealloc {
            using value_type = void;
    
            void *last_deallocated_ptr;
            std::size_t last_allocated_len;
    
            ~vector_mmaprealloc() {
                     assert(posix::munmap(ptr, last_allocated_len) == 0);
             }
            auto allocate(std::size_t _len) {
                   auto len = round_to_pagesize(_len);
                   if (likely(last_deallocated_ptr)) 
                        return realloc(len);
                  else 
                         return alloc(len);
            }
        protected:
            static constexpr auto get_map_flags() noexcept {
                   return MAP_PRIVATE | MAP_ANONYMOUS | MAP_UNINITIALIZED;
            }
            auto alloc(std::size_t len) {
                    if (auto ret = 
                    posix::mmap(nullptr, len, PROT_READ | PROT_WRITE, get_map_flags(), -1, 0)) {
                         last_allocated_len = len;
                        return ret;
                    } else {
                         assert(errno == ENOMEM | EAGAIN);
                         throw bad_alloc(strerror(nullptr));
                    }
            }
            auto realloc(std::size_t len) {
                    if (auto ret = posix::mremap(last_dsallocated_ptr, last_alloc_len, len, MREMAP_MAYMOVE)) {
                         last_allocated_len = len;
                         return ret;
                    } else {
                          assert(errno != EINVAL);
                          throw bad_alloc(__PRETTY_FUNCTION__);
                    }
            }
        public:
            void deallocate(void *ptr) {
                   last_deallocated_ptr = ptr;
            }
            constexpr auto round_to_pagesize(std::size_t len) const noexcept {
                   return (len + magic_num) & ~magic_num;
            }
            static inline constexpr const auto magic_num = std::size_t magic_num = 4096 - 1;
    };