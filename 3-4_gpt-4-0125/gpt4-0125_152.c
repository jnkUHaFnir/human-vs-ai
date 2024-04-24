typedef double (*Operation)(double, double);

typedef struct {
    Operation op;
    double param;
} OperationClosure;
double wrapper_add(double x, OperationClosure *closure) {
    // Assuming the original function takes param as the first argument
    return closure->op(closure->param, x);
}
OperationClosure* OP_PAdd(Operation f, double param3) {
    OperationClosure* oc = (OperationClosure*)malloc(sizeof(OperationClosure));
    if (!oc) return NULL; // Always check for malloc failure

    oc->op = f;
    oc->param = param3;

    return oc;
}
// Example operation
double myOperation(double param, double x) {
    return param * x;
}

int main() {
    // Create a new "function"
    OperationClosure* oc = OP_PAdd(myOperation, 5.0);

    // "Call" this new function
    double result = wrapper_add(2.0, oc);

    printf("Result: %f\n", result);

    // Cleanup
    free(oc);

    return 0;
}
