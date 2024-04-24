#include <iostream>
#include <cstdlib>

class Allocator {
public:
    template<typename Type, typename... Args>
    Type* Alloc(unsigned int size, Args&&... args) {
        void* rawMemory = malloc(size);
        if (rawMemory == nullptr) {
            // Handle allocation failure
            return nullptr;
        }
        
        return new(rawMemory) Type(std::forward<Args>(args)...);
    }
};

class CustomType {
public:
    CustomType(int a, float b) {
        std::cout << "CustomType constructed with arguments: " << a << ", " << b << std::endl;
    }
};

int main() {
    Allocator* allocator = new Allocator();
    
    // Allocating CustomType with arguments using the allocator
    CustomType* customObj = allocator->Alloc<CustomType>(sizeof(CustomType), 42, 3.14f);
    
    // Don't forget to free memory allocated by the allocator
    customObj->~CustomType();
    free(customObj);
    
    delete allocator;
    
    return 0;
}
