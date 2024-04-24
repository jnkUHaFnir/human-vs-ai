#include <stdio.h>
#include <stdlib.h>

double newFunction(double a, double x) {
    return a * x; // Example implementation of a new function
}

double (*OP_PAdd(double (*f)(double, double), double param3))(double, double) {
    double (*newFunc)(double, double) = (double (*)(double, double))malloc(sizeof(double (*)(double, double)));
    
    if(newFunc == NULL) {
        // Handle allocation failure
        return NULL;
    }

    // Create a new function based on the input function and parameter
    *newFunc = *f;
    *newFunc = *newFunc + param3;

    return newFunc;
}

int main() {
    double (*f1)(double, double) = &f1;
    double (*f2)(double, double) = &f2;

    double a = 2.0; // Just for example
    double param3 = 3.0; // Just for example

    double (*newFunc)(double, double) = OP_PAdd(f1, param3);

    if(newFunc != NULL) {
        double result = (*newFunc)(a, a);
        printf("Result: %f\n", result);

        // Don't forget to free the allocated memory when done using the function
        free(newFunc);
    }

    return 0;
}
