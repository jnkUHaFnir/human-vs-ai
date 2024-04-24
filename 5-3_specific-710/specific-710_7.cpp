class MyClass {
public:
    MyClass(const MyClass &other); // Copy constructor
};
class MyClass {
public:
    MyClass& operator=(const MyClass &other); // Copy assignment operator
};
class NoCopyClass {
private:
    NoCopyClass(const NoCopyClass &other); // private copy constructor
    NoCopyClass& operator=(const NoCopyClass &other); // private copy assignment operator
public:
    NoCopyClass() {}
};
