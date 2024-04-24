#include <iostream>
#include <map>

// Define a map to store pointers and their corresponding allocations
std::map<void*, size_t> allocationMap;

// Custom implementation of operator new
void* operator new(size_t size) {
    void* ptr = malloc(size);
    allocationMap[ptr] = size;
    std::cout << "Allocated memory at: " << ptr << " with size: " << size << std::endl;
    return ptr;
}

// Custom implementation of operator delete
void operator delete(void* ptr) noexcept {
    if (allocationMap.find(ptr) != allocationMap.end()) {
        size_t size = allocationMap[ptr];
        std::cout << "Deallocating memory at: " << ptr << " with size: " << size << std::endl;
        allocationMap.erase(ptr);
        free(ptr);
    } else {
        // Handle error case where ptr is not found in the allocation map
        std::cerr << "Trying to deallocate memory that was not allocated by custom operator new!" << std::endl;
    }
}

// Usage example
int main() {
    int* arr = new int[10];
    delete[] arr;

    return 0;
}
