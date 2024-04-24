#include <iostream>
#include <new>

class Allocator {
public:
    template<typename Type, typename... Args>
    Type* Alloc(size_t size, Args&&... args) {
        void* memory = malloc(size);
        if (!memory) {
            return nullptr;
        }
        
        return new(memory) Type(std::forward<Args>(args)...);
    }
};

#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__)

// Example usage
class MyObject {
public:
    MyObject(int val1, float val2) {
        std::cout << "Constructing MyObject with values " << val1 << " and " << val2 << std::endl;
    }
};

int main() {
    Allocator* customAllocator = new Allocator();
    
    // Allocate and construct MyObject with arguments
    MyObject* obj = MYNEW(MyObject, customAllocator, 42, 3.14f);

    delete obj;
    delete customAllocator;
    
    return 0;
}
