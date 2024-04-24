#include <stdio.h>
#include <stdarg.h>

// Define a thunk function that takes a function pointer and variable arguments
int thunk(void (*func)(), ...) {
    va_list args;
    va_start(args, func);

    // Example: Call the function with three integer arguments
    int arg1 = va_arg(args, int);
    int arg2 = va_arg(args, int);
    int arg3 = va_arg(args, int);

    // Call the function with the arguments
    func(arg1, arg2, arg3);

    va_end(args);
}

// Example function to be thunked
void example_function(int arg1, int arg2, int arg3) {
    printf("Arguments: %d, %d, %d\n", arg1, arg2, arg3);
}

int main() {
    // Thunk the example function with three integer arguments
    thunk((void (*)())example_function, 1, 2, 3);

    return 0;
}
