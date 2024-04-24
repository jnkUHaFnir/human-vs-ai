class MyClass {
public:
    // Copy constructor
    MyClass(const MyClass& other) {
        // Copy the state from 'other' to 'this'
    }
};
class MyClass {
public:
    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this != &other) {
            // Copy the state from 'other' to 'this'
        }
        return *this;
    }
};
class NonCopyableClass {
private:
    // Private copy constructor and copy assignment operator
    NonCopyableClass(const NonCopyableClass& other);
    NonCopyableClass& operator=(const NonCopyableClass& other);

public:
    // Constructor and other member functions
};
