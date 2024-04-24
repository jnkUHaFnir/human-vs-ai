#include <stdio.h>
#include <stdlib.h>

// Original function prototype
double f1(double alpha, double x);
double f2(double beta, double x);

// New function that represents addition of the original function with a constant
double PAdd(double alpha, double x, double param3) {
    return alpha + param3;
}

// Function to create a new function dynamically and return a pointer to it
double (*OP_PAdd(double (*f)(double, double), double param3))(double, double) {
    typedef double (*newFuncType)(double, double);

    // Dynamically allocate memory for the new function
    newFuncType newFunc = (newFuncType)malloc(sizeof(newFuncType));

    // Assign the function pointer to the addition function
    *newFunc = PAdd;

    return newFunc;
}

int main() {
    double (*newFunc)(double, double);

    // Get the new function representing the addition of f1 and param3
    newFunc = OP_PAdd(f1, 5.0);

    // Testing the new function
    double result = (*newFunc)(10.0, 2.0);
    printf("Result: %f\n", result);

    // Free dynamically allocated memory
    free(newFunc);

    return 0;
}
