#include <iostream>
#include <map>

// Define a map to store allocation information
std::map<void*, size_t> allocationMap;

void* operator new(size_t size) {
    void* ptr = malloc(size);
    allocationMap[ptr] = size;
    std::cout << "Allocated " << size << " bytes at address " << ptr << std::endl;
    return ptr;
}

void operator delete(void* ptr) noexcept {
    std::cout << "Deallocating memory at address " << ptr << std::endl;
    free(ptr);
    allocationMap.erase(ptr);
}

int main() {
    // Test the custom memory allocation functions
    int* arr = new int[5];
    delete[] arr;

    // Check for any memory leaks at the end of the application
    if (!allocationMap.empty()) {
        std::cout << "Memory leak detected!" << std::endl;
        // Print out the addresses of leaked memory
        for (const auto& pair : allocationMap) {
            std::cout << "Leaked memory at address " << pair.first << " with size " << pair.second << std::endl;
        }
    } else {
        std::cout << "No memory leaks detected." << std::endl;
    }

    return 0;
}
