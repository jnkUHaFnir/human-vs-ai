#include <iostream>

class NoCopyClass {
private:
    NoCopyClass(const NoCopyClass& other);
    NoCopyClass& operator=(const NoCopyClass& other);
    
public:
    NoCopyClass() {
        // Constructor implementation
    }
    
    void someFunction() {
        std::cout << "Some function called" << std::endl;
    }
};

int main() {
    NoCopyClass obj1;
    // NoCopyClass obj2 = obj1; // Error: copy constructor is private
    // NoCopyClass obj3;
    // obj3 = obj1; // Error: copy assignment operator is private
    
    obj1.someFunction();

    return 0;
}
