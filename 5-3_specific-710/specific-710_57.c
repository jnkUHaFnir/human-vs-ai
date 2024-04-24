#include <stdio.h>

// Define the function
void myFunction(int i, void (*funcs[])(), int x) {
    if (i < x) {
        funcs[i](); // Call the function at index i
        myFunction(i + 1, funcs, x); // Call the next function recursively
    }
}

// Define functions to call
void function1() {
    printf("Function 1 called\n");
}

void function2() {
    printf("Function 2 called\n");
}

void function3() {
    printf("Function 3 called\n");
}

int main() {
    void (*funcs[3])() = {function1, function2, function3}; // Array of function pointers

    myFunction(0, funcs, 3); // Call myFunction to execute functions in the array 3 times

    return 0;
}
