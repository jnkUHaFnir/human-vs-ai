#include <iostream>
#include <cstdlib>

// Custom Allocator class
class MyAllocator {
public:
    template<typename Type, typename... Args>
    Type* Alloc(Args&&... args) {
        return new (std::malloc(sizeof(Type))) Type(std::forward<Args>(args)...);
    }
};

// Usage of custom allocator with variadic template
#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(__VA_ARGS__)

// Example usage
class MyType {
public:
    MyType(int var1, int var2) {
        std::cout << "Constructor called with var1: " << var1 << ", var2: " << var2 << std::endl;
    }
};

int main() {
    MyAllocator* allocator = new MyAllocator();
    MyType* myObj = MYNEW(MyType, allocator, 10, 20);
    
    delete allocator;
    
    // Deallocate memory
    myObj->~MyType();
    std::free(myObj);
    
    return 0;
}
