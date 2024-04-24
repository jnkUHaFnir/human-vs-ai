#include <stdio.h>
#include <stdlib.h>

typedef double (*func_ptr)(double, double);

double f1(double alpha, double x) {
    return alpha * x; // Just an example function, you can change implementation
}

double f2(double beta, double x) {
    return beta + x; // Just an example function, you can change implementation
}

double OP_Addition(func_ptr f, func_ptr g, double param1, double param2, double x) {
    double z1 = (*f)(param1, x);
    double z2 = (*g)(param2, x);
    return z1 + z2;
}

// Function to return a pointer to a new function which is the sum of the input functions
func_ptr OP_PAdd(func_ptr f, double param3) {
    // Allocate memory for the new function pointer
    func_ptr new_func = (func_ptr)malloc(sizeof(func_ptr));
    
    // Define the new function
    *new_func = [f, param3](double alpha, double x) {
        return (*f)(alpha, x) + param3; // You can modify this to suit your logic
    };
    
    return new_func;
}

int main() {
    func_ptr f = f1;
    func_ptr g = f2;
    
    double param1 = 2.0, param2 = 3.0, param3 = 5.0;
    double x = 10.0;
    
    double result1 = OP_Addition(f, g, param1, param2, x);
    printf("Result of OP_Addition: %f\n", result1);
    
    func_ptr new_func = OP_PAdd(f, param3);
    double result2 = (*new_func)(param1, x);
    printf("Result of OP_PAdd: %f\n", result2);
    
    free(new_func); // Make sure to free the allocated memory
    
    return 0;
}
