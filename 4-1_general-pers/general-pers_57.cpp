#include <iostream>

// Define the function that we want to call x times
void myFunction() {
    static int count = 0;
    std::cout << "Calling function " << count << " time(s)" << std::endl;
    count++;
}

// Define a function that recursively calls the function x times
void callFunctionNTimes(int n, void (*func)()) {
    if (n > 0) {
        callFunctionNTimes(n - 1, func);
        func();
    }
}

int main() {
    // Number of times to call the function
    int x = 5;

    // Array of function pointers
    void (*functionPointers[1])() = {myFunction};

    // Call the function x times using recursion and function pointers
    callFunctionNTimes(x, functionPointers[0]);

    return 0;
}
