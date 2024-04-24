template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}
#define MYNEW_N(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), __VA_ARGS__)

// Example usage:
int* myInteger = MYNEW_N(int, myCustomAllocator, 42);
MyClass* myObj = MYNEW_N(MyClass, myCustomAllocator, arg1, arg2, arg3);
