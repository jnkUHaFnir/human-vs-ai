#include <iostream>
#include <cstdlib>

class Allocator {
public:
    template<typename Type, typename... Args>
    Type* Alloc(unsigned int size, Args&&... args) {
        void* rawMemory = std::malloc(size);
        if (!rawMemory) {
            return nullptr;
        }
        return new(rawMemory) Type(std::forward<Args>(args)...);
    }
};

#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), __VA_ARGS)

struct MyStruct {
    int value;
    MyStruct(int v) : value(v) {}
};

int main() {
    Allocator* customAllocator = new Allocator();
    
    MyStruct* obj1 = MYNEW(MyStruct, customAllocator, 5);
    MyStruct* obj2 = MYNEW(MyStruct, customAllocator, 10);

    std::cout << obj1->value << std::endl; // Output: 5
    std::cout << obj2->value << std::endl; // Output: 10

    // Don't forget to manually call the destructors for objects created using placement new
    obj1->~MyStruct();
    obj2->~MyStruct();

    // Don't forget to free the memory allocated by the custom allocator
    free(obj1);
    free(obj2);

    delete customAllocator;

    return 0;
}
