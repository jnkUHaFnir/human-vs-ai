#include <iostream>

class NoCopy {
private:
    NoCopy(const NoCopy&); // private copy constructor
    void operator=(const NoCopy&); // private copy assignment operator

public:
    NoCopy() {
        // Constructor code
    }
};

int main() {
    NoCopy obj1;
    // NoCopy obj2 = obj1; // Compiler error: attempt to copy constructor
    // NoCopy obj3;
    // obj3 = obj1; // Compiler error: attempt to copy assignment
    return 0;
}
