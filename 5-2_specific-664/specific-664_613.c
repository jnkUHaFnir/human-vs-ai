#include <stdio.h>

// Define a function pointer type that matches the signature of the arbitrary function
typedef int (*ArbitraryFunction)(int, int, int);

// Thunk function for x86
int Thunk_x86(ArbitraryFunction func, int arg1, int arg2, int arg3) {
    int result;
    __asm {
        push arg3
        push arg2
        push arg1
        call func
        add esp, 12  // Clean up the stack
        mov result, eax
    }
    return result;
}

// Thunk function for x64
int Thunk_x64(ArbitraryFunction func, int arg1, int arg2, int arg3) {
    int result;
    __asm {
        mov ecx, arg3
        mov edx, arg2
        push arg1
        call func
        mov result, eax
    }
    return result;
}

// Example arbitrary function
int ExampleFunction(int a, int b, int c) {
    return a + b + c;
}

int main() {
    // Thunk the ExampleFunction with arguments 1, 2, and 3
    int result_x86 = Thunk_x86(ExampleFunction, 1, 2, 3);
    int result_x64 = Thunk_x64(ExampleFunction, 1, 2, 3);

    printf("Result (x86): %d\n", result_x86);
    printf("Result (x64): %d\n", result_x64);

    return 0;
}
