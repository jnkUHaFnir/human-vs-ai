#include <iostream>
#include <map>
#include <new>

std::map<void*, std::size_t> AllocationMap;

void* operator new(std::size_t size) {
    void* ptr = malloc(size);
    AllocationMap[ptr] = size;
    return ptr;
}

void operator delete(void* ptr) noexcept {
    AllocationMap.erase(ptr);
    free(ptr);
}

int main() {
    int* ptr = new int(42);
    // Your code using custom new/delete
    delete ptr;

    // At the end of the application, check for memory leaks
    if (AllocationMap.empty()) {
        std::cout << "No memory leaks detected" << std::endl;
    } else {
        std::cout << "Memory leaks detected:" << std::endl;
        for (const auto& entry : AllocationMap) {
            std::cout << "Memory leak at address: " << entry.first << " Size: " << entry.second << std::endl;
        }
    }

    return 0;
}
