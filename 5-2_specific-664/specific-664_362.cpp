#include <iostream>

class NoCopy {
private:
    NoCopy(const NoCopy& other); // Declaring the copy constructor as private
    NoCopy& operator=(const NoCopy& other); // Declaring the copy assignment operator as private

public:
    NoCopy() {
        // Constructor
    }

    void display() {
        std::cout << "NoCopy object" << std::endl;
    }
};

int main() {
    NoCopy obj1;
    // NoCopy obj2 = obj1; // This will cause a compile-time error due to inaccessible copy constructor
    // NoCopy obj3;
    // obj3 = obj1; // This will cause a compile-time error due to inaccessible copy assignment operator

    obj1.display();

    return 0;
}
