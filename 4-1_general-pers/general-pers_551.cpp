#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__)

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    void* rawMemory = malloc(size);
    if (!rawMemory) {
        // Handle memory allocation failure
        return nullptr;
    }
    
    return new(rawMemory) Type(std::forward<Args>(args)...);
}
struct MyStruct {
    int a;
    double b;
    
    MyStruct(int a, double b) : a(a), b(b) {}
};

// Allocate an object of MyStruct with constructor arguments
MyStruct* obj = MYNEW(MyStruct, myAllocator, 10, 3.14);
