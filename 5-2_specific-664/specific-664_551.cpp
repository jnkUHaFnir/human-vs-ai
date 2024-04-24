#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__)

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args) // Allocator::Alloc<Type>
{
    return (Type*)new(malloc(size)) Type(std::forward<Args>(args)...);
}
// Example usage for a Type with constructor that takes no arguments
Type* myInstance = MYNEW(MyType, myAllocator);

// Example usage for a Type with constructor that takes one argument
Type* myInstance = MYNEW(MyType, myAllocator, arg1);

// Example usage for a Type with constructor that takes two arguments
Type* myInstance = MYNEW(MyType, myAllocator, arg1, arg2);
