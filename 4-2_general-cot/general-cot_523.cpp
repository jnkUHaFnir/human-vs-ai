#include <iostream>

class NonCopyableClass {
private:
    NonCopyableClass(const NonCopyableClass& other);             // Private copy constructor
    NonCopyableClass& operator=(const NonCopyableClass& other);  // Private copy assignment operator

public:
    NonCopyableClass() {
        std::cout << "NonCopyableClass created\n";
    }

    void doSomething() {
        std::cout << "Doing something...\n";
    }
};

int main() {
    NonCopyableClass obj1;
    // NonCopyableClass obj2 = obj1; // Error: copy constructor is private
    // NonCopyableClass obj3;
    // obj3 = obj1; // Error: copy assignment operator is private

    obj1.doSomething();

    return 0;
}
