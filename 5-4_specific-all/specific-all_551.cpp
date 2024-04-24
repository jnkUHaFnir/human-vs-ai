#include <iostream>
#include <cstdlib>

class MyAllocator {
public:
    template<typename Type, typename... Args>
    Type* Alloc(size_t size, Args&&... args) {
        void* rawMemory = std::malloc(size);
        if (rawMemory == nullptr) {
            return nullptr;
        }
        
        return new(rawMemory) Type(std::forward<Args>(args)...);
    }
};

class MyClass {
public:
    int num1;
    float num2;

    MyClass(int n1, float n2) : num1(n1), num2(n2) {
        std::cout << "Custom constructor called with values: " << num1 << " and " << num2 << std::endl;
    }
};

int main() {
    MyAllocator* allocator = new MyAllocator;

    MyClass* obj1 = allocator->Alloc<MyClass>(sizeof(MyClass), 10, 3.14f);
    if (obj1 != nullptr) {
        // Object created successfully
    } else {
        // Error handling for allocation failure
    }

    // Clean up memory
    obj1->~MyClass(); // Explicitly call destructor
    std::free(obj1);

    delete allocator;

    return 0;
}
