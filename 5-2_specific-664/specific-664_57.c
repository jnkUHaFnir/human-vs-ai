#include <stdio.h>

// Define a function type
typedef void (*FunctionPointer)();

// Define the function to be called x times
void myFunction() {
    printf("Function called\n");
}

// Recursive function to call the function x times
void callFunctionNTimes(FunctionPointer funcArray[], int n, int x) {
    if (x <= 0) {
        return;
    }
    
    funcArray[n-x](); // Call the function at index (n-x) from the array
    callFunctionNTimes(funcArray, n, x-1); // Recursively call the next function
}

int main() {
    // Define an array of function pointers
    FunctionPointer funcArray[5] = { myFunction, myFunction, myFunction, myFunction, myFunction };
    
    // Call the function 5 times without using a loop
    callFunctionNTimes(funcArray, 5, 5);
    
    return 0;
}
