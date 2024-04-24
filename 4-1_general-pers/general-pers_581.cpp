ClassName(const ClassName& other);
ClassName& operator=(const ClassName& other);
#include <iostream>

class NoCopyClass {
private:
    // Private copy constructor and copy assignment operator to prevent copying
    NoCopyClass(const NoCopyClass& other);
    NoCopyClass& operator=(const NoCopyClass& other);

public:
    NoCopyClass() {
        std::cout << "Object created!" << std::endl;
    }

    ~NoCopyClass() {
        std::cout << "Object destroyed!" << std::endl;
    }
};

int main() {
    NoCopyClass obj1;
    // NoCopyClass obj2 = obj1;  // This line will result in a compilation error due to private copy constructor
    // NoCopyClass obj3;
    // obj3 = obj1;  // This line will result in a compilation error due to private copy assignment operator

    return 0;
}
