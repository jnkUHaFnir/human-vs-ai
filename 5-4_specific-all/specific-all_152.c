#include <stdio.h>
#include <stdlib.h>

// Define the type of function pointer
typedef double (*function_ptr)(double, double);

// Define a struct that holds the function pointer and parameter
typedef struct {
    function_ptr func;
    double param;
} FunctionWrapper;

// Wrapper function (addition with a constant parameter)
double wrapped_function(double x, double param) {
    FunctionWrapper *wrapper = (FunctionWrapper *)param;
    return wrapper->func(x, wrapper->param);
}

// Function that returns a pointer to a new function
void *OP_PAdd(double (*f)(double, double), double param3) {
    // Allocate memory for the function wrapper
    FunctionWrapper *wrapper = (FunctionWrapper *)malloc(sizeof(FunctionWrapper));
    if (wrapper == NULL) {
        return NULL; // Memory allocation failed
    }

    // Assign values to the function wrapper
    wrapper->func = f;
    wrapper->param = param3;

    // Return the function pointer to the wrapped function
    return (void *)wrapped_function;
}

// Example usage
double f1(double alpha, double x) {
    return alpha * x;
}

int main() {
    // Create a new function pointer with f1 and a parameter
    function_ptr new_func = OP_PAdd(f1, 5.0);

    // Use the new function pointer
    double result = new_func(2.0);
    printf("Result: %f\n", result);

    // Free the memory allocated for the function wrapper
    free((FunctionWrapper *)new_func);

    return 0;
}
