#define MYNEW(...) \
    Allocator->Alloc(__VA_ARGS__)

template<typename Type, typename... Args>
Type* Alloc(unsigned int size, Args&&... args)
{
    return new(malloc(size)) Type(std::forward<Args>(args)...);
}
// Define a class without default constructor
class MyClass {
public:
    MyClass(int value) : value_(value) {}

    void printValue() {
        std::cout << "Value: " << value_ << std::endl;
    }

private:
    int value_;
};

// Allocate memory for MyClass with constructor argument
MyClass* obj = MYNEW(MyClass, 42);
obj->printValue();

// Deallocate memory
delete obj;
