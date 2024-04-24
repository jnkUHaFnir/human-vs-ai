#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__);

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args) // Allocator::Alloc<Type>
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}
// Usage examples:
// Allocate Type with default constructor
Type* obj1 = MYNEW(Type, Allocator);

// Allocate Type with constructor that takes one argument
Type* obj2 = MYNEW(Type, Allocator, arg1);

// Allocate Type with constructor that takes multiple arguments
Type* obj3 = MYNEW(Type, Allocator, arg1, arg2, arg3);
