#include <iostream>
#include <map>
#include <cstdlib>

std::map<void*, size_t> allocatedMemory;

void* operator new(size_t size) {
    void* ptr = malloc(size);
    allocatedMemory[ptr] = size;
    return ptr;
}

void operator delete(void* ptr) noexcept {
    allocatedMemory.erase(ptr);
    free(ptr);
}

// Define global new and delete overrides for array new and delete if needed
void* operator new[](size_t size) {
    void* ptr = malloc(size);
    allocatedMemory[ptr] = size;
    return ptr;
}

void operator delete[](void* ptr) noexcept {
    allocatedMemory.erase(ptr);
    free(ptr);
}

// Define a function to check for memory leaks at the end of the application
void checkForMemoryLeaks() {
    if (!allocatedMemory.empty()) {
        std::cerr << "Memory leaks detected:" << std::endl;
        for (const auto& pair : allocatedMemory) {
            std::cerr << "Leaked memory at: " << pair.first << ", size: " << pair.second << std::endl;
        }
    } else {
        std::cout << "No memory leaks detected." << std::endl;
    }
}

// Usage example
int main() {
    int* ptr1 = new int(5);
    int* ptr2 = new int(10);

    // Simulate a memory leak
    // int* leakedMemory = new int(15);

    delete ptr1;
    delete ptr2;

    checkForMemoryLeaks();

    return 0;
}
