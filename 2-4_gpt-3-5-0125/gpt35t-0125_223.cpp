#include <new>
#include <cstdlib>

class Allocator {
public:
    template<typename Type, typename... Args>
    Type* Alloc(unsigned int size, Args&&... args) {
        return new(malloc(size)) Type(std::forward<Args>(args)...);
    }
};

#define MYNEW(Type, Allocator, ...) Allocator->Alloc<Type>(sizeof(Type), __VA_ARGS)

struct MyType {
    MyType(int x, double y) : data(x + y) {}
    float data;
};

int main() {
    Allocator* allocator = new Allocator;
    MyType* myObject = MYNEW(MyType, allocator, 10, 3.14);

    delete myObject;
    delete allocator;
    return 0;
}
