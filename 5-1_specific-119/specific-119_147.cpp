#include <iostream>
#include <map>
#include <new>

// Define a map to keep track of active allocations
std::map<void*, std::size_t> allocatedMemory;

void* operator new(std::size_t size) {
    void* ptr = malloc(size);
    allocatedMemory[ptr] = size; // Track the allocation
    return ptr;
}

void operator delete(void* ptr) noexcept {
    auto it = allocatedMemory.find(ptr);
    if (it != allocatedMemory.end()) {
        free(ptr);
        allocatedMemory.erase(it); // Remove from tracking
    }
}

int main() {
    // Test memory allocations
    int* p1 = new int(42);
    int* p2 = new int(100);

    // Free memory
    delete p1;
    delete p2;

    // Check for any leaked memory
    if (allocatedMemory.empty()) {
        std::cout << "No memory leaks detected.\n";
    } else {
        std::cout << "Memory leaks detected!\n";
    }

    return 0;
}
