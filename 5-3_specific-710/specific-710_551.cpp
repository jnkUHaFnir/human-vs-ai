// Custom allocator with variadic templates
template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}

// Macro for allocator with variadic templates
#define MYNEW_N(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), ##__VA_ARGS__)

// Example usage
struct MyType {
    int a, b;
    MyType(int x, int y) : a(x), b(y) {}
};

int main() {
    MyType* obj = MYNEW_N(MyType, allocator, 10, 20);
}
