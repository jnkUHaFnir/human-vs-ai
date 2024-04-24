#include <iostream>

class NoCopy {
private:
    NoCopy(const NoCopy& other); // Copy constructor declared as private but not implemented
    NoCopy& operator=(const NoCopy& other); // Copy assignment operator declared as private but not implemented

public:
    NoCopy() { }

    void print() {
        std::cout << "NoCopy object" << std::endl;
    }
};

int main() {
    NoCopy obj1;
    NoCopy obj2 = obj1; // This will trigger a compile-time error because copy constructor is private
    return 0;
}
