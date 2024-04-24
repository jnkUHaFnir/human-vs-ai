#include <utility> // For std::forward
#include <cstdlib> // For malloc and free

class Allocator {
public:
    // Variadic template to accept any number of constructor arguments
    template<typename Type, typename... Args>
    static Type* Alloc(Args&&... args) {
        void* raw_memory = malloc(sizeof(Type));
        if (!raw_memory) {
            // Handle out of memory case, throw an exception or return nullptr
            return nullptr; // As an example
        }
        
        // Use placement new with perfect forwarding of constructor arguments
        return new (raw_memory) Type(std::forward<Args>(args)...);
    }

    // Corresponding Dealloc function
    template<typename Type>
    static void Dealloc(Type* object) {
        if (object) {
            // Explicitly call the destructor
            object->~Type();

            // Free the block of memory
            free(static_cast<void*>(object));
        }
    }
};

// Macro using the Alloc function with perfect forwarding
#define MYNEW(Allocator, Type, ...) Allocator::Alloc<Type>(__VA_ARGS__)
class SomeType {
public:
    SomeType(int a, double b) {
        // Constructor with two arguments
    }
};

int main() {
    SomeType* myObject = MYNEW(Allocator, SomeType, 10, 3.14);
    // ...
    Allocator::Dealloc<SomeType>(myObject);
    return 0;
}
