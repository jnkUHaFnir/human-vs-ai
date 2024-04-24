#include <utility> // For std::forward

#define MYNEW(Type, Allocator, ...) (Allocator)->Alloc<Type>(__VA_ARGS__)

// Allocator::Alloc implementation with support for variadic constructor arguments
template<typename Type, typename... Args>
Type* Alloc(Args&&... args) // Perfect forwarding of constructor arguments
{
    void* rawMemory = malloc(sizeof(Type));
    if (!rawMemory) {
        // Handle memory allocation failure (throw exception or return nullptr)
        return nullptr;
    }
    return new(rawMemory) Type(std::forward<Args>(args)...); // Perfect forwarding
}

// Example usage of MYNEW macro with a hypothetical custom allocator instance
struct ExampleType {
    ExampleType(int x, double y) {
        // Example constructor body
    }
};

int main() {
    auto myAllocator = /* Instance of your custom allocator */;

    // Using MYNEW macro to allocate an ExampleType, forwarding 2 constructor arguments
    ExampleType* example = MYNEW(ExampleType, myAllocator, 42, 3.14);
}
