#include <stdio.h>

// Define a sample function to be called
void sampleFunction() {
    printf("Function called!\n");
}

// Define a function to call another function x times using recursion
void callFunctionNTimes(void (*func)(), int n) {
    if (n > 0) {
        func(); // Call the function

        // Recursively call the function n-1 times
        callFunctionNTimes(func, n - 1);
    }
}

int main() {
    // Create an array of function pointers
    void (*funcArray[1])() = {sampleFunction};

    // Call the function 5 times using the function pointer array
    callFunctionNTimes(funcArray[0], 5);

    return 0;
}
