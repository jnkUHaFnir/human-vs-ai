#include <iostream>

// Define a function pointer type that matches the function signature we want to thunk
typedef int (*FuncPtr)(int, int, int);

// Thunk function with a fixed number of integer arguments
int Thunk(FuncPtr func, int arg1, int arg2, int arg3) {
    return func(arg1, arg2, arg3);
}

// Sample function to be thunked
int SampleFunction(int a, int b, int c) {
    return a + b + c;
}

int main() {
    // Call the SampleFunction directly
    std::cout << "Result of SampleFunction: " << SampleFunction(1, 2, 3) << std::endl;

    // Thunk the SampleFunction and call through the thunk
    std::cout << "Result of Thunked SampleFunction: " << Thunk(SampleFunction, 1, 2, 3) << std::endl;

    return 0;
}
