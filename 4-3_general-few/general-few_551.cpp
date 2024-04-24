#define MYNEW(Type, Allocator, ...) Allocator->Construct<Type>(sizeof(Type), ##__VA_ARGS__)
template<typename Type, typename... Args>
Type* Construct(unsigned int size, Args&&... args) // Allocator::Construct<Type>
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}

// Example of using MYNEW with different constructor arguments
class ExampleClass {
public:
    ExampleClass(int x, int y) : x_(x), y_(y) {}

private:
    int x_;
    int y_;
};

// Usage
ExampleClass* obj = MYNEW(ExampleClass, Allocator, 10, 20);
