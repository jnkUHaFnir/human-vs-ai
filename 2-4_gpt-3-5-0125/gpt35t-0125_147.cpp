#include <iostream>
#include <map>

std::map<void*, size_t> allocations;

void* operator new(size_t size) {
    void* ptr = malloc(size);
    allocations[ptr] = size;
    return ptr;
}

void operator delete(void* ptr) noexcept {
    free(ptr);
    allocations.erase(ptr);
}

int main() {
    int* ptr = new int(5);

    for (auto& entry : allocations) {
        std::cout << "Memory address: " << entry.first << ", Size: " << entry.second << std::endl;
    }

    delete ptr;

    return 0;
}
