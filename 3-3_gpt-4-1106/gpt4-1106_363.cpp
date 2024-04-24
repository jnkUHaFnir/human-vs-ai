class MyClass {
public:
    MyClass(const MyClass &other) {
        // Copy each field from 'other' to 'this'
        this->field = other.field;
    }
    // ...
};
class MyClass {
public:
    MyClass& operator=(const MyClass &other) {
        // Guard against self-assignment
        if (this != &other) {
            // Copy each field from 'other' to 'this'
            this->field = other.field;
        }
        return *this;
    }
    // ...
};
class NonCopyable {
public:
    // Delete copy constructor and copy assignment operator
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable& operator=(const NonCopyable &) = delete;

    // Other members...
};
