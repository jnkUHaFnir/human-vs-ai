#include <iostream>

// Define a function type that matches the signature of the function you want to thunk
using ArbitraryFunctionType = int(*)(int, int, void*);

// Thunk function that calls the arbitrary function
int ThunkFunction(int arg1, int arg2, void* arg3)
{
    // Here you can implement any additional logic before or after calling the original function
    // For simplicity, we directly call the original function here
    ArbitraryFunctionType originalFunction = reinterpret_cast<ArbitraryFunctionType>(arg3);
    
    // Call the original function with the provided arguments
    return originalFunction(arg1, arg2, arg3);
}

int main()
{
    // Example of how to use the thunk
    ArbitraryFunctionType originalFunction = [](int arg1, int arg2, void* arg3) -> int {
        // Example implementation of the original function
        std::cout << "Original function called with arguments: " << arg1 << ", " << arg2 << std::endl;
        return arg1 + arg2;
    };

    // Create a thunk function pointer
    ArbitraryFunctionType thunk = ThunkFunction;

    // Call the thunk function
    int result = thunk(10, 20, reinterpret_cast<void*>(originalFunction));

    std::cout << "Result: " << result << std::endl;

    return 0;
}
