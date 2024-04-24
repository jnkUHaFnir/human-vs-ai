#include <iostream>

class NoCopy {
private:
    NoCopy(const NoCopy& other); // private copy constructor
    NoCopy& operator=(const NoCopy& other); // private copy assignment operator
public:
    NoCopy() { }
    void print() {
        std::cout << "NoCopy object" << std::endl;
    }
};

int main() {
    NoCopy obj1;
    // NoCopy obj2 = obj1; // Error: copy constructor is private
    // NoCopy obj3;
    // obj3 = obj1; // Error: copy assignment operator is private

    obj1.print();

    return 0;
}
