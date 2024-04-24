#include <iostream>
#include <new>

// Forward declaration of Allocator class
template<class AllocatorType>
class Allocator;

// Sample non-default constructor parameters struct
struct ConVar1 {
    int data;
};

// Allocator class
template<class AllocatorType>
class Allocator {
public:
    template<typename Type>
    Type* Alloc(std::size_t size) {
        return static_cast<Type*>(malloc(size));
    }

    template<typename Type, typename... Args>
    Type* AllocAndConstruct(std::size_t size, Args&&... args) {
        void* memory = malloc(size);
        Type* obj = new(memory) Type(std::forward<Args>(args)...);
        return obj;
    }
};

// Sample custom Vector class
class Vector {
public:
    int val;
    Vector(int v) : val(v) {}
};

int main() {
    Allocator<int> myAllocator;
    
    // Allocate and construct object with non-default constructor
    ConVar1 cv1 = {42};
    Vector* vec = myAllocator.AllocAndConstruct<Vector>(sizeof(Vector), cv1);

    std::cout << "Value: " << vec->val << std::endl;

    // Don't forget to free the memory allocated by malloc
    free(vec);

    return 0;
}
