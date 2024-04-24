#include <iostream>
#include <map>

// Define a map to keep track of allocated memory
std::map<void*, size_t> memoryMap;

// Overload global new operator
void* operator new(size_t size) {
    void *ptr = malloc(size);

    // Add allocated memory to the map
    memoryMap[ptr] = size;
    
    return ptr;
}

// Overload global delete operator
void operator delete(void* ptr) noexcept {
    // Remove deallocated memory from the map
    memoryMap.erase(ptr);
    
    free(ptr);
}

int main() {
    // Test allocation
    int* ptr = new int;
    
    // Check memoryMap
    for (const auto& pair : memoryMap) {
        std::cout << "Memory allocated at: " << pair.first << " Size: " << pair.second << std::endl;
    }
    
    // Test deallocation
    delete ptr;
    
    // Check memoryMap after deallocation
    for (const auto& pair : memoryMap) {
        std::cout << "Memory allocated at: " << pair.first << " Size: " << pair.second << std::endl;
    }
    
    return 0;
}
