ClassName(const ClassName& other);
ClassName& operator=(const ClassName& other);
class MyClass {
public:
    MyClass() { /* constructor */ }
    
    // Declare but do not define the copy constructor
    MyClass(const MyClass& other) = delete;
    
    // Declare but do not define the copy assignment operator
    MyClass& operator=(const MyClass& other) = delete;
};
