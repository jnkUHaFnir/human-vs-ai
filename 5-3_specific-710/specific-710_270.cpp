#include <iostream>

class NoCopy {
private:
    // Declare the copy constructor and copy assignment operator as private
    NoCopy(const NoCopy&);
    NoCopy& operator=(const NoCopy&);

public:
    NoCopy() {
        std::cout << "Constructor called" << std::endl;
    }

    ~NoCopy() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    NoCopy obj1;
    // NoCopy obj2 = obj1; // This will result in a compile-time error
    // NoCopy obj3;
    // obj3 = obj1; // This will result in a compile-time error

    return 0;
}
