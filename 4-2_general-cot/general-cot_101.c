#include <stdarg.h>
#include <stdio.h>

// Define the thunk function that takes the arbitrary function pointer and the number of arguments
int thunk(void (*func)(), int numArgs, ...) {
    va_list args;
    
    // Initialize va_list to iterate through arguments
    va_start(args, numArgs);

    // Call the function with the variable number of arguments
    switch (numArgs) {
        case 0:
            func();
            break;
        case 1:
            func(va_arg(args, int));
            break;
        case 2:
            func(va_arg(args, int), va_arg(args, int));
            break;
        // Add more cases as needed for additional arguments
        default:
            // Handle invalid number of arguments
            fprintf(stderr, "Unsupported number of arguments\n");
            break;
    }

    va_end(args);

    return 0;
}

// Example function that we will thunk
void arbitraryFunc(int a, int b, int c) {
    printf("Arguments: %d %d %d\n", a, b, c);
}

int main() {
    // Thunk the arbitrary function with 3 arguments
    thunk((void (*)())arbitraryFunc, 3, 10, 20, 30);

    return 0;
}
