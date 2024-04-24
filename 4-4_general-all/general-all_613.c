#include <stdio.h>

// Define a thunk function pointer type
typedef int (*ThunkFunction)(int, void*);

// Define a generic thunk function that can be used to call any function with fixed arguments
int ThunkFunctionGeneric(int arg1, void* arg2) {
    // Cast the passed function pointer to the desired function signature and call it
    ThunkFunction func = (ThunkFunction)arg2;
    return func(arg1, arg2);
}

int AddFunction(int a, int b) {
    return a + b;
}

int main() {
    // Thunk an arbitrary function (AddFunction) with a fixed number of arguments
    ThunkFunction thunk = &ThunkFunctionGeneric;
    int result = thunk(5, (void*)AddFunction);

    printf("Result: %d\n", result);

    return 0;
}
