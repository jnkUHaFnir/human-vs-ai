#include <stdio.h>
#include <stdarg.h>

// Define a typedef for the arbitrary function pointer
typedef int (*ArbitraryFunctionPtr)(int, ...);

// Thunk function that takes an arbitrary function pointer and a variable number of arguments
int thunk(ArbitraryFunctionPtr funcPtr, int numArgs, ...) {
    va_list argList;
    va_start(argList, numArgs);

    int result = funcPtr(numArgs, argList);

    va_end(argList);

    return result;
}

// Example arbitrary function to be thunked
int arbitraryFunction(int numArgs, ...) {
    va_list argList;
    va_start(argList, numArgs);

    int sum = 0;
    for (int i = 0; i < numArgs; i++) {
        int arg = va_arg(argList, int);
        sum += arg;
    }

    va_end(argList);

    return sum;
}

int main() {
    // Thunk the arbitrary function with 3 arguments
    int result = thunk(arbitraryFunction, 3, 10, 20, 30);

    printf("Result: %d\n", result);

    return 0;
}
