class MyClass {
public:
    MyClass(const MyClass& other) {
        // copy constructor implementation
    }
};
class MyClass {
public:
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            // copy assignment operator implementation
        }
        return *this;
    }
};
class NoCopyClass {
private:
    NoCopyClass(const NoCopyClass& other);
    NoCopyClass& operator=(const NoCopyClass& other);

public:
    // class definition
};
