#include <iostream>
#include <memory>
#include <limits>

template<class T>
struct Mallocator {
    using value_type = T;

    Mallocator() noexcept = default;

    template<class U>
    Mallocator(const Mallocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T)) {
            throw std::bad_alloc();
        }
        T* ptr = static_cast<T*>(::operator new(n * sizeof(T)));
        if (!ptr) {
            throw std::bad_alloc();
        }
        return ptr;
    }

    void deallocate(T* p, std::size_t) noexcept {
        ::operator delete(p);
    }
};

template<class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) {
    return true;
}

template<class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) {
    return false;
}

int main() {
    std::allocator<int> stdAlloc;
    int* stdPtr = stdAlloc.allocate(1);
    *stdPtr = 42;
    std::cout << "Standard allocator: " << *stdPtr << std::endl;
    stdAlloc.deallocate(stdPtr, 1);

    Mallocator<int> customAlloc;
    int* customPtr = customAlloc.allocate(1);
    *customPtr = 42;
    std::cout << "Custom allocator: " << *customPtr << std::endl;
    customAlloc.deallocate(customPtr, 1);

    return 0;
}
