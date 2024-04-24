#include <stdio.h>

typedef int (*ArbitraryFunction)(int, int, int);

int trampoline(int arg1, int arg2, int arg3) {
    ArbitraryFunction func = (ArbitraryFunction)0x12345678; // Arbitrary function address

    // Call the arbitrary function with the fixed number of arguments
    return func(arg1, arg2, arg3);
}

int main() {
    // Thunk an arbitrary function with 3 integer arguments
    int result = trampoline(5, 10, 15);
    printf("Result: %d\n", result);

    return 0;
}
#include <stdio.h>

typedef int (*ArbitraryFunction)(int, int, int);

int trampoline(int arg1, int arg2, int arg3) {
    ArbitraryFunction func = (ArbitraryFunction)0xFFFFFFFFFFFFFFFF; // Arbitrary function address

    // Call the arbitrary function with the fixed number of arguments
    return func(arg1, arg2, arg3);
}

int main() {
    // Thunk an arbitrary function with 3 integer arguments
    int result = trampoline(5, 10, 15);
    printf("Result: %d\n", result);

    return 0;
}
