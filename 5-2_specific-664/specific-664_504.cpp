#include <iostream>
#include <vector>
#include <memory>

template <typename T>
struct geometric_allocator : std::allocator<T> {
    using Base = std::allocator<T>;

    template <typename U>
    struct rebind {
        using other = geometric_allocator<U>;
    };

    geometric_allocator() noexcept {}
    geometric_allocator(const geometric_allocator& other) noexcept : Base(other) {}

    template <typename U>
    geometric_allocator(const geometric_allocator<U>& other) noexcept : Base(other) {}

    template <typename U>
    geometric_allocator(geometric_allocator<U>&& other) noexcept : Base(std::move(other)) {}

    T* allocate(std::size_t n) {
        if (n == 0) {
            return nullptr;
        }
        if (n > this->max_size()) {
            // Throw an error or handle the allocation failure as needed
            throw std::bad_array_new_length();
        }

        // Custom growth factor, e.g., multiply the requested size by 2
        std::size_t newSize = n * 2;

        return Base::allocate(newSize);
    }

    void deallocate(T* p, std::size_t n) noexcept {
        Base::deallocate(p, n);
    }
};

int main() {
    const int size = 1000000000;    
    std::vector<int, geometric_allocator<int>> b(size);
    for(int i = 0; i < size; i++) {
        b[i] = i;
    }

    return 0;
}
