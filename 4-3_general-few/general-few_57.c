#include <stdio.h>

// Define your function
void myFunction() {
    static int count = 0;
    printf("Function called %d times\n", ++count);
}

// Define a function to call another function x times recursively
void callFunctionXTimes(void (*fn)(), int x) {
    if (x > 0) {
        fn();
        callFunctionXTimes(fn, x - 1);
    }
}

int main() {
    // Array of function pointers (in this case, just one function)
    void (*functionPointers[])(void) = {myFunction};

    // Call the function x times (e.g., 5 times)
    callFunctionXTimes(functionPointers[0], 5);

    return 0;
}
