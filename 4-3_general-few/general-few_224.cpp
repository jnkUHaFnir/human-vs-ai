#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), __VA_ARGS);

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args) // Allocator::Alloc<Type>
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}
class CustomType {
public:
    CustomType(int val1, const std::string& val2) {
        // initialize the object
    }
};

// Allocating CustomType object with constructor arguments
CustomType* obj = MYNEW(CustomType, allocator, 42, "hello");
