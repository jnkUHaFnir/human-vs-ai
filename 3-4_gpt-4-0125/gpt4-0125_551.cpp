#include <utility> // For std::forward
#include <stdlib.h> // For malloc
#include <new> // For placement new

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args) // Allocator::Alloc<Type>
{
    void* rawMemory = malloc(size); // Allocate raw memory
    if (!rawMemory) { /* handle allocation failure */ }

    // Using placement new with perfect forwarding
    return new(rawMemory) Type(std::forward<Args>(args)...);
}
#define MYNEW(Type, Allocator, ...) \
        Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__)
// Assuming Type has a constructor that matches this signature
auto obj = MYNEW(Type, allocator, arg1, arg2, arg3);
