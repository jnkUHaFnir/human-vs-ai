#include <stdio.h>
#include <stdlib.h>

// Custom function type for functions that take two double inputs and return a double
typedef double (*DoubleDoubleFunc)(double, double);

// Function that adds a given constant to the result of a given function
double PAdd(double x, double y, double (*f)(double, double), double param) {
    return f(x, y) + param;
}

// Function that dynamically creates a new function pointer that adds the constant to the input function result
DoubleDoubleFunc OP_PAdd(DoubleDoubleFunc f, double param) {
    DoubleDoubleFunc newFunc = (DoubleDoubleFunc)malloc(sizeof(DoubleDoubleFunc));
    
    if (newFunc != NULL) {
        *newFunc = [f, param](double x, double y) -> double {
            return f(x, y) + param;
        };

        return newFunc;
    } else {
        // Handle the case where memory allocation failed
        return NULL;
    }
}

int main() {
    // Example usage
    double alpha = 1.0;
    double beta = 2.0;
    double x = 5.0;
    double param3 = 10.0;

    // Define the functions f1 and f2
    DoubleDoubleFunc f1 = [alpha](double x, double y) -> double { return alpha * x + y; };
    DoubleDoubleFunc f2 = [beta](double x, double y) -> double { return beta * x - y; };

    // Define a new function that adds param3 to the result of f1
    DoubleDoubleFunc newFunc = OP_PAdd(f1, param3);

    // Use the new function
    double result = (*newFunc)(x, x);

    // Output the result
    printf("Result: %f\n", result);

    // Free the dynamically allocated function pointer
    free(newFunc);

    return 0;
}
