#include <iostream>
#include <memory>

template <typename T>
struct Mallocator {
    using value_type = T;

    Mallocator() noexcept = default;

    template <class U>
    Mallocator(const Mallocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        if (n > std::size_t(-1) / sizeof(T)) {
            throw std::bad_array_new_length();
        }

        if (auto p = static_cast<T*>(std::malloc(n * sizeof(T)))) {
            return p;
        } else {
            throw std::bad_alloc();
        }
    }

    void deallocate(T* p, std::size_t) noexcept {
        std::free(p);
    }

    template <class U>
    bool operator==(const Mallocator<U>&) const noexcept {
        return true;
    }

    template <class U>
    bool operator!=(const Mallocator<U>&) const noexcept {
        return false;
    }
};

int main() {
    std::vector<int, Mallocator<int>> vec = {1, 2, 3, 4, 5};

    for (const auto& num : vec) {
        std::cout << num << " ";
    }

    return 0;
}
