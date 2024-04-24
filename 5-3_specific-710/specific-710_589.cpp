#include <iostream>

class NoCopyClass {
private:
    // Private copy constructor and copy assignment operator
    NoCopyClass(const NoCopyClass&);
    NoCopyClass& operator=(const NoCopyClass&);

public:
    NoCopyClass() {
        std::cout << "Object created" << std::endl;
    }

    ~NoCopyClass() {
        std::cout << "Object destroyed" << std::endl;
    }
};

int main() {
    NoCopyClass obj1;
    // NoCopyClass obj2 = obj1;  // This will cause a compilation error
    // NoCopyClass obj3;
    // obj3 = obj1;  // This will also cause a compilation error

    return 0;
}
