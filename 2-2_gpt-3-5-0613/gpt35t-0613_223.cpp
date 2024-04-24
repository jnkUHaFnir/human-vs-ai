#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), __VA_ARGS__);

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}
struct MyType {
    MyType(int a, int b) {
        // constructor code
    }
};

// default constructor
MyType* p1 = MYNEW(MyType, allocator);

// constructor with arguments
int arg1 = 10;
int arg2 = 20;
MyType* p2 = MYNEW(MyType, allocator, arg1, arg2);
