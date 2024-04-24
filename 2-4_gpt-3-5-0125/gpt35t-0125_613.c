#include <stdio.h>

// Function pointer type for the arbitrary function
typedef int (*ArbitraryFunc)(int, int, int);

// Trampoline function that jumps to the actual function
int trampoline(void *funcPtr, int arg1, int arg2, int arg3) {
    // Call the function with the given arguments
    return ((ArbitraryFunc)funcPtr)(arg1, arg2, arg3);
}

int main() {
    ArbitraryFunc myFunc = (ArbitraryFunc)someFunction; // Replace someFunction with your function pointer
    void *myFuncPtr = (void *)myFunc;

    // Execute the trampoline function with the function pointer and arguments
    int result = trampoline(myFuncPtr, 1, 2, 3); // Replace 1, 2, 3 with your arguments

    printf("Result: %d\n", result);

    return 0;
}
