#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class CustomAllocator {
public:
    using value_type = T;

    CustomAllocator() noexcept = default;

    template <class U>
    CustomAllocator(const CustomAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        return static_cast<T*>(operator new(n * sizeof(T)));
    }

    void deallocate(T* p, std::size_t) noexcept {
        operator delete(p);
    }
};

int main() {
    // Example usage of CustomAllocator with std::vector
    std::vector<int, CustomAllocator<int>> vec{CustomAllocator<int>()};
    vec.push_back(42);
    
    // Example usage of CustomAllocator with std::unique_ptr
    std::unique_ptr<int, CustomAllocator<int>> ptr(new int(10), CustomAllocator<int>());

    return 0;
}
