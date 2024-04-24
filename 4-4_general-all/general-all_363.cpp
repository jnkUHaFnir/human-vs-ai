#include <iostream>

class NoCopyClass {
private:
    // Declare copy constructor and copy assignment operator as private and unimplemented
    NoCopyClass(const NoCopyClass&);
    NoCopyClass& operator=(const NoCopyClass&);

public:
    NoCopyClass() {
        std::cout << "Constructor called" << std::endl;
    }

    ~NoCopyClass() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    NoCopyClass obj1; // Creating object 1

    // This will result in a compile-time error due to private copy constructor and assignment operator
    // NoCopyClass obj2 = obj1; // Trying to copy obj1
    // NoCopyClass obj3(obj1); // Trying to copy obj1

    return 0;
}
