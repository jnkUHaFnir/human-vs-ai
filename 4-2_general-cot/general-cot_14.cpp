#include <iostream>
#include <memory>
#include <limits>

template <class T>
struct Mallocator {
    using value_type = T;

    Mallocator() noexcept = default;

    template <class U>
    constexpr Mallocator(const Mallocator<U>&) noexcept {}

    [[nodiscard]] T* allocate(std::size_t n) {
        if (n > std::numeric_limits<std::size_t>::max() / sizeof(T))
            throw std::bad_alloc();
        if (auto p = static_cast<T*>(std::malloc(n * sizeof(T))))
            return p;
        throw std::bad_alloc();
    }

    void deallocate(T* p, std::size_t) noexcept {
        std::free(p);
    }
};

template <class T, class U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) {
    return true;
}

template <class T, class U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) {
    return false;
}

int main() {
    // Example usage of Mallocator
    std::vector<int, Mallocator<int>> vec{1, 2, 3, 4, 5};

    for (const auto& element : vec) {
        std::cout << element << " ";
    }

    return 0;
}
