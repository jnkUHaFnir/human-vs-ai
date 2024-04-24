#include <iostream>
#include <functional>

void callFunctions(std::function<void()> functions[], int count) {
    if (count > 0) {
        functions[0]();
        callFunctions(functions, count - 1);
    }
}

void function1() {
    std::cout << "Function 1 called" << std::endl;
}

void function2() {
    std::cout << "Function 2 called" << std::endl;
}

void function3() {
    std::cout << "Function 3 called" << std::endl;
}

int main() {
    std::function<void()> functions[] = {function1, function2, function3};
    
    callFunctions(functions, 5); // Calls each function 5 times
    
    return 0;
}
