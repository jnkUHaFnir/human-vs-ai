#include <stdio.h>
#include <stdlib.h>

// Define a struct to hold the function pointer and the constant parameter
typedef struct {
    double (*func)(double, double);
    double param;
} FunctionWithParam;

// Function that adds a constant value (param) to the result of a function (func)
double additionFunc(double alpha, double x) {
    FunctionWithParam *data = (FunctionWithParam *)alpha;
    double result = data->func(data->param, x);
    return result + data->param;
}

// Function to create and return a new function struct
void *OP_PAdd(double (*f)(double, double), double param3) {
    // Allocate memory for the struct
    FunctionWithParam *data = (FunctionWithParam *)malloc(sizeof(FunctionWithParam));

    // Assign the function pointer and parameter to the struct
    data->func = f;
    data->param = param3;

    // Return the struct as a void pointer
    return (void *)data;
}

// Test function
double f1(double alpha, double x) {
    return alpha * x;
}

int main() {
    double alpha = 2.0;
    double beta = 3.0;
    double x = 5.0;

    double result;
    
    // Create a new function representing f1 + alpha
    void *newFunc = OP_PAdd(f1, alpha);

    // Call the new function
    result = additionFunc((double)newFunc, x);

    printf("Result: %f\n", result);

    // Free the allocated memory
    free(newFunc);

    return 0;
}
