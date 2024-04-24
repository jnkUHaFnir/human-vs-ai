#include <stdio.h>
#include <stdlib.h>

// Define the function signature
typedef double (*funcPtr)(double, double);

// Function to add a constant parameter to the input function
funcPtr OP_PAdd(double (*f)(double, double), double param3) {
    // Define a new function that adds param3 to the result of f(x)
    double newFunc(double x, double y) {
        return f(x, y) + param3;
    }
    
    // Return a pointer to the new function
    return &newFunc;
}

// Sample functions f1 and f2
double f1(double alpha, double x) {
    return 2 * alpha * x;
}

double f2(double beta, double x) {
    return beta + x;
}

int main() {
    // Create new functions by adding a constant to f1 and f2
    funcPtr newF1 = OP_PAdd(f1, 5.0);
    funcPtr newF2 = OP_PAdd(f2, 10.0);
    
    // Test the new functions
    printf("New f1(3.0, 2.0): %f\n", newF1(3.0, 2.0));
    printf("New f2(3.0, 2.0): %f\n", newF2(3.0, 2.0));
    
    return 0;
}
