#include <iostream>

// The function you want to call 'x' times
void myFunction() {
    std::cout << "Hello, World!" << std::endl;
}

// Helper recursive function to call a function 'x' times
void callFunctionXTimes(void (*func)(), int x) {
    if (x > 0) {
        func(); // Call the target function
        callFunctionXTimes(func, x - 1); // Recursive call
    }
}

int main() {
    int x = 5; // Number of times you want to call the function
    callFunctionXTimes(myFunction, x);

    return 0;
}
