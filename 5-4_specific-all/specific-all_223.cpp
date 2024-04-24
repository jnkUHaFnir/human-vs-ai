#define MYNEW(...) MYNEW_IMPL(__VA_ARGS__)

#define MYNEW_IMPL(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__)

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}
