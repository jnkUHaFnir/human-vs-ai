#include <stdio.h>

// Define a function pointer type that matches the signature of the arbitrary function
typedef int (*ArbitraryFunctionType)(int, int, int);

// Define the trampoline function that will call the arbitrary function with fixed arguments
int Trampoline(int arg1, int arg2, int arg3) {
    // Cast the function pointer to the correct signature
    ArbitraryFunctionType arbitraryFunction = (ArbitraryFunctionType)0x12345678; // Replace 0x12345678 with the address of your function

    // Call the arbitrary function with fixed arguments
    return arbitraryFunction(arg1, arg2, arg3);
}

int main() {
    // Call the trampoline function with fixed arguments
    int result = Trampoline(10, 20, 30);

    printf("Result: %d\n", result);

    return 0;
}
