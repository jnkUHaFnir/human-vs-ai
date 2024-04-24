#include <cstddef>
#include <iostream>
#include <memory>
#include <type_traits>

template <typename T>
class Mallocator {
public:
    // Type definitions
    using value_type = T;
    
    // Constructor
    Mallocator() noexcept = default;

    // Destructor
    ~Mallocator() noexcept = default;

    // Allocate memory for n objects of type T
    T* allocate(std::size_t n) {
        static_assert(std::is_default_constructible<T>::value, "Mallocator<T> requires a default constructible type.");
        if (n > std::size_t(-1) / sizeof(T)) {
            throw std::bad_array_new_length();
        }
        T* ptr = static_cast<T*>(operator new(n * sizeof(T)));
        if (!ptr) {
            throw std::bad_alloc();
        }
        return ptr;
    }

    // Deallocate memory
    void deallocate(T* ptr, std::size_t /* n */) noexcept {
        operator delete(ptr);
    }
};

// Test the Mallocator
int main() {
    Mallocator<int> allocator;
    int* ptr = allocator.allocate(5);
    for (int i = 0; i < 5; ++i) {
        ptr[i] = i;
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << ptr[i] << ' ';
    }
    allocator.deallocate(ptr, 5);

    return 0;
}
