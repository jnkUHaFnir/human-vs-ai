#include <iostream>
#include <cstdlib>
#include <map>
#include <mutex>

std::map<void*, size_t> allocations;
std::mutex allocMutex;

void* operator new(std::size_t size) {
    void* p = std::malloc(size);
    if (!p) throw std::bad_alloc(); // Required by the standard.
    
    {
        std::lock_guard<std::mutex> guard(allocMutex);
        allocations[p] = size;
    }

    return p;
}

void operator delete(void* p) noexcept {
    {
        std::lock_guard<std::mutex> guard(allocMutex);
        allocations.erase(p);
    }
    
    std::free(p);
}

int main() {
    int* myInt = new int(5); // Custom new operator will track this allocation.
    delete myInt; // Custom delete operator will remove the tracking.
    
    // At the end, check for un-freed allocations.
    if (!allocations.empty()) {
        for (const auto& pair : allocations) {
            std::cout << "Leaked at address " << pair.first
                      << " of size " << pair.second << " bytes\n";
        }
    }
    
    return 0;
}
