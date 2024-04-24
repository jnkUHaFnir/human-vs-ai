#include <iostream>

class NoCopy {
private:
    NoCopy(const NoCopy&); // private copy constructor
    NoCopy& operator=(const NoCopy&); // private copy assignment operator

public:
    NoCopy() {
        // Constructor implementation
    }

    // Other member functions
};

int main() {
    NoCopy obj1;
    // NoCopy obj2 = obj1; // This would cause a compile-time error due to private copy constructor

    return 0;
}
