#include <iostream>

class NonCopyable {
private:
    NonCopyable(const NonCopyable&); // declare copy constructor as private
    NonCopyable& operator=(const NonCopyable&); // declare copy assignment operator as private

public:
    NonCopyable() {
        std::cout << "NonCopyable object created" << std::endl;
    }

    void doSomething() {
        std::cout << "Doing something..." << std::endl;
    }
};

int main() {
    NonCopyable obj1;
    // NonCopyable obj2 = obj1; // This will cause a compilation error since copy constructor is private
    // NonCopyable obj3;
    // obj3 = obj1; // This will cause a compilation error since copy assignment operator  is private

    obj1.doSomething();

    return 0;
}
