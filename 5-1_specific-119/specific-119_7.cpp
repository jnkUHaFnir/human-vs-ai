class MyClass {
public:
    MyClass(const MyClass& other) {
        // Copy constructor code here
    }
};
class MyClass {
public:
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            // Copy assignment code here
        }
        return *this;
    }
};
class NoCopy {
private:
    NoCopy(const NoCopy& other);
    NoCopy& operator=(const NoCopy& other);
public:
    NoCopy() {
        // Constructor code here
    }
};
