#include <iostream>
#include <unordered_map>

// Define your custom new and delete operators
void* operator new(size_t size) {
    void* ptr = malloc(size);
    
    // Store the allocated pointer in a map
    // (This is just a simple example, you can use a more sophisticated data structure for actual tracking)
    // key: pointer, value: allocation size
    // Note: This can cause memory leaks if not deleted properly
    allocationMap[ptr] = size;

    return ptr;
}

void operator delete(void* ptr) noexcept {
    // Remove the pointer from the map when memory is deallocated
    allocationMap.erase(ptr);
    free(ptr);
}

// Define a map to keep track of allocations
std::unordered_map<void*, size_t> allocationMap;

// Declare a global new and delete operator
#define new MY_NEW
#define delete MY_DELETE

int main() {
    // Example usage
    int* value = new int(5);
    
    // Check the allocationMap for active allocations
    for (auto const& [ptr, size] : allocationMap) {
        std::cout << "Active Allocation: " << ptr << " Size: " << size << std::endl;
    }

    // Delete the allocated memory
    delete value;

    return 0;
}
