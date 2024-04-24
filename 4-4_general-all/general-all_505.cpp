#include <iostream>
#include <vector>
#include <cmath>

template <typename T>
class CustomAllocator : public std::allocator<T> {
public:
    typedef size_t size_type;
    typedef T* pointer;

    // Allocate memory in powers of 2
    pointer allocate(size_type n, const void* hint = 0) {
        size_type new_capacity = static_cast<size_type>(std::pow(2, static_cast<size_type>(std::ceil(std::log2(n))));
        return std::allocator<T>::allocate(new_capacity, hint);
    }
};

int main(int argc, char *argv[]) {
    const int size = 1000000000;
    std::vector<int, CustomAllocator<int>> b;
    for (int i = 0; i < size; i++) {
        b.push_back(i);
    }

    return 0;
}
