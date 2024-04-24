#include <iostream>

class NonCopyable {
private:
    NonCopyable(const NonCopyable &); // disallow copy constructor
    NonCopyable& operator=(const NonCopyable &); // disallow copy assignment operator

public:
    NonCopyable() {
        // Constructor
    }

    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }
};

int main() {
    NonCopyable obj1;
    obj1.doSomething();

    // This will cause a compile-time error
    // NonCopyable obj2 = obj1; // Error: calling copy constructor

    return 0;
}
