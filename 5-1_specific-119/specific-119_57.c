#include <stdio.h>

// Define the function that will be called x times
void myFunction() {
    printf("Function called\n");
}

// Define a function to call the function recursively x times
void callFunctionXTimes(void (*functions[])(void), int x) {
    if (x > 0) {
        functions[x-1](); // Call the function at index x-1
        callFunctionXTimes(functions, x-1); // Recursively call the function with x decremented
    }
}

int main() {
    void (*functionPointers[])(void) = {myFunction, myFunction, myFunction}; // Array of function pointers

    callFunctionXTimes(functionPointers, 3); // Call the functions 3 times

    return 0;
}
