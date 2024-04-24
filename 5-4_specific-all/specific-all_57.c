#include <stdio.h>

// Function to be called x times
void myFunction() {
    printf("Hello, World!\n");
}

// Function that will recursively call the function x times
void callFunctionNTimes(void (*func)(), int n) {
    if (n > 0) {
        func();
        callFunctionNTimes(func, n - 1);
    }
}

int main() {
    // Array of function pointers
    void (*funcArray[1])() = {myFunction};

    int x = 5; // Number of times to call the function

    // Call the function x times without using a loop
    callFunctionNTimes(funcArray[0], x);

    return 0;
}
