ClassName(const ClassName &source);
ClassName& operator=(const ClassName& rhs);
class MyClass {
private:
    MyClass(const MyClass&); // private copy constructor
    MyClass& operator=(const MyClass&); // private copy assignment operator

public:
    MyClass() { }
    // other members and methods
};
