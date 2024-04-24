#include <iostream>
#include <functional>

// Define a thunk function for a function with 3 integer arguments
std::function<int(int, int, int)> thunkFunction = [](int a, int b, int c) {
    // Call the arbitrary function here
    // For demonstration, just adding the three arguments
    return a + b + c;
};

int main() {
    // Call the thunked function
    int result = thunkFunction(1, 2, 3);
    
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}
