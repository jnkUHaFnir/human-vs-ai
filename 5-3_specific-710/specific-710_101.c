#include <stdio.h>
#include <stdint.h>

typedef int (*ArbitraryFunctionPtr)(int, int, int); // Define the function pointer signature

int ArbitraryFunction(int arg1, int arg2, int arg3) {
    return arg1 + arg2 + arg3;
}

int ThunkArbitraryFunction(int arg1, int arg2, int arg3) {
    ArbitraryFunctionPtr funcPtr = ArbitraryFunction; // Assign the target function pointer
    return funcPtr(arg1, arg2, arg3); // Call the target function through the function pointer
}

int main() {
    int result = ThunkArbitraryFunction(1, 2, 3);
    printf("Result: %d\n", result); // Output: Result: 6

    return 0;
}
#include <stdio.h>
#include <stdint.h>

typedef int (*ArbitraryFunctionPtr)(int, int, int); // Define the function pointer signature

int ArbitraryFunction(int arg1, int arg2, int arg3) {
    return arg1 + arg2 + arg3;
}

int ThunkArbitraryFunction(int arg1, int arg2, int arg3) {
    ArbitraryFunctionPtr funcPtr = ArbitraryFunction; // Assign the target function pointer
    return funcPtr(arg1, arg2, arg3); // Call the target function through the function pointer
}

int main() {
    int result = ThunkArbitraryFunction(1, 2, 3);
    printf("Result: %d\n", result); // Output: Result: 6

    return 0;
}
