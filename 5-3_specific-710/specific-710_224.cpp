#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__);

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}
class Example {
public:
    Example(int arg1, double arg2) {
        // Constructor implementation
    }
};

// Allocating memory for 'Example' type with constructor arguments
MYNEW(Example, allocator, 42, 3.14);
