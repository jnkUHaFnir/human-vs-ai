#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__);

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return (Type*)new(malloc(sizeof(Type))) Type(std::forward<Args>(args)...);
}
class CustomType {
public:
    CustomType(int value1, double value2) {
        // constructor implementation
    }
};

// Using MYNEW with constructor arguments for CustomType
CustomType* obj = MYNEW(CustomType, Allocator, 42, 3.14);
