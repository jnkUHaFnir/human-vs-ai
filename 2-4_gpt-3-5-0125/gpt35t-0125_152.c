double new_function(double param, double x, double (*f)(double, double)) {
    return f(param, x);
}

double* OP_PAdd(double (*f)(double, double), double param) {
    double (*new_function_pointer)(double, double) = new_function;
    return new_function_pointer;
}

int main() {
    double (*result_function)(double, double) = OP_PAdd(f1, 5.0);

    double result = (*result_function)(10.0, 15.0);

    printf("Result: %f\n", result);

    return 0;
}
