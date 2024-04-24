#include <iostream>

class NoCopy {
private:
    NoCopy(const NoCopy&); // Declare copy constructor as private without implementation
    NoCopy& operator=(const NoCopy&); // Declare copy assignment operator as private without implementation

public:
    NoCopy() {
        std::cout << "Object created" << std::endl;
    }

    ~NoCopy() {
        std::cout << "Object destroyed" << std::endl;
    }
};

int main() {
    NoCopy obj1;
    // NoCopy obj2 = obj1; // This line will cause a compile error due to inaccessible copy constructor
    // NoCopy obj3;
    // obj3 = obj1; // This line will cause a compile error due to inaccessible copy assignment operator

    return 0;
}
