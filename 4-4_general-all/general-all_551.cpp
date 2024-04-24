#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS)

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}
// Create an instance of a type without default constructor
TypeWithoutDefaultConstructor* obj = MYNEW(TypeWithoutDefaultConstructor, allocator, arg1, arg2, arg3);
