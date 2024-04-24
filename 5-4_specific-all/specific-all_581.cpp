class MyClass {
public:
    MyClass(const MyClass &other) {
        // Perform copy of 'other' object
    }
};
class MyClass {
public:
    MyClass& operator=(const MyClass &other) {
        if (this != &other) {
            // Perform copy of 'other' object
        }
        return *this;
    }
};
class NoCopyClass {
private:
    NoCopyClass(const NoCopyClass &other); // Declare but do not define
    NoCopyClass& operator=(const NoCopyClass &other); // Declare but do not define
};
