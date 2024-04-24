#include <stdio.h>

// Define a function to be called
void myFunction() {
    printf("Function called\n");
}

// Define a recursive function to call a function x times
void callFunctionNTimes(void (**funcArray)(), int n, int x) {
    if (n > 0) {
        funcArray[x](); // Call the function using function pointer at index x
        callFunctionNTimes(funcArray, n - 1, x); // Recursive call with decremented n
    }
}

int main() {
    void (*funcArray[1])() = { myFunction }; // Array of function pointers containing only myFunction
    int numCalls = 5; // Number of times to call the function

    callFunctionNTimes(funcArray, numCalls, 0); // Call myFunction 5 times

    return 0;
}
