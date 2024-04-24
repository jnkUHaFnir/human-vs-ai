#include <iostream>
#include <map>
#include <cstdlib>

std::map<void*, size_t> allocations; // Map to store pointers and their sizes

void* operator new(size_t size) {
    void* ptr = std::malloc(size);
    allocations[ptr] = size;
    return ptr;
}

void operator delete(void* ptr) noexcept {
    auto it = allocations.find(ptr);
    if (it != allocations.end()) {
        std::free(ptr);
        allocations.erase(it);
    }
}

// You can also overload array new and delete operators
void* operator new[](size_t size) {
    void* ptr = std::malloc(size);
    allocations[ptr] = size;
    return ptr;
}

void operator delete[](void* ptr) noexcept {
    auto it = allocations.find(ptr);
    if (it != allocations.end()) {
        std::free(ptr);
        allocations.erase(it);
    }
}

// Define a function to check for unfreed memory at the end
void checkForLeaks() {
    for (const auto& allocation : allocations) {
        std::cout << "Memory leak detected. Size: " << allocation.second << std::endl;
        // Optionally, you can add more details, like stack traces if available.
    }
}

int main() {
    // Your application code here
    
    // At the end of the application
    checkForLeaks();
    
    return 0;
}
