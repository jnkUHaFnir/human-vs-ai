#include <vector>
#include <iostream>

template <typename T>
struct GeometricAllocator : public std::allocator<T> {
    typedef size_t size_type;
    typedef T* pointer;

    pointer allocate(size_type n, const void* hint = 0) {
        size_type newSize = n * 2; // Grow geometrically
        std::cout << "Allocating " << newSize << " elements\n";
        return std::allocator<T>::allocate(newSize, hint);
    }
};

int main() {
    const int size = 1000000000;
    std::vector<int, GeometricAllocator<int>> b;
    for(int i = 0; i < size; i++) {
        b.push_back(i);
    }    

    return 0;
}
