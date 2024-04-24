#include <stdio.h>
#include <stdlib.h>

// Define a function type for functions accepting two doubles and returning a double
typedef double (*funcPtr)(double, double);

// Function to add a constant value to a function and return the resulting function
funcPtr OP_PAdd(double (*f)(double, double), double param3) {
    // Define a new function that adds the constant value to the result of the provided function
    double addedFunction(double alpha, double x) {
        return f(alpha, x) + param3;
    }
    
    // Return a pointer to the new function
    return addedFunction;
}

// Example function f1
double f1(double alpha, double x) {
    return alpha * x;
}

// Example function f2
double f2(double beta, double x) {
    return beta + x;
}

int main() {
    // Create a new function by adding a constant value to f1
    funcPtr newFunction = OP_PAdd(f1, 5.0);
    
    // Test the new function
    double result = newFunction(2.0, 3.0);
    printf("Result: %f\n", result);
    
    return 0;
}
