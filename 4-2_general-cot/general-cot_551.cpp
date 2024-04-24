#include <iostream>
#include <cstdlib>

class CustomAllocator {
public:
    template<typename Type, typename... Args>
    Type* Alloc(size_t size, Args&&... args) {
        void* rawMemory = std::malloc(size);
        if (!rawMemory) {
            return nullptr;
        }
        return new(rawMemory) Type(std::forward<Args>(args)...);
    }

    template<typename Type>
    void Dealloc(Type* ptr) {
        ptr->~Type();
        std::free(ptr);
    }
};

#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), __VA_ARGS)
#define MYDELETE(Type, Allocator, Ptr) Allocator->Dealloc<Type>(Ptr)

class MyClass {
public:
    MyClass(int value) : m_value(value) {
        std::cout << "Constructed with value: " << m_value << std::endl;
    }

private:
    int m_value;
};

int main() {
    CustomAllocator* allocator = new CustomAllocator();

    MyClass* obj1 = MYNEW(MyClass, allocator, 5);
    MyClass* obj2 = MYNEW(MyClass, allocator, 10);

    MYDELETE(MyClass, allocator, obj1);
    MYDELETE(MyClass, allocator, obj2);

    delete allocator;

    return 0;
}
