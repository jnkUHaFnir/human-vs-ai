class Foo {
public:
    Foo(const Foo& other) {
        // Code to copy the state from 'other' to this instance
    }
};
class Foo {
public:
    Foo& operator=(const Foo& other) {
        if (this != &other) { // Protect against self-assignment
            // Code to copy the state from 'other' to this instance
        }
        return *this;
    }
};
class Foo {
public:
    Foo(const Foo& other) = delete; // Copy constructor
    Foo& operator=(const Foo& other) = delete; // Copy assignment operator
};
class Foo {
private:
    Foo(const Foo& other); // Copy constructor
    Foo& operator=(const Foo& other); // Copy assignment operator
};
