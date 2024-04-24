class MyClass {
public:
    MyClass(int x, double y) { /* Constructor implementation */ }
};

// Allocator hypothetical instance
Allocator allocator;

int main() {
    int arg1 = 10;
    double arg2 = 20.0;

    // Directly calling Alloc with constructor parameters for MyClass
    MyClass* myObject = allocator.Alloc<MyClass>(arg1, arg2);

    // Don't forget to deallocate with the appropriate mechanism!
}
