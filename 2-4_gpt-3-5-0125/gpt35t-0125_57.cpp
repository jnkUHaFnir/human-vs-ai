#include <iostream>

// Define a function that calls itself recursively x times
void callFunction(int x, void (*func)())
{
    if (x > 0)
    {
        func();
        callFunction(x - 1, func);
    }
}

// Define the function that we want to call x times
void myFunction()
{
    std::cout << "Calling myFunction!\n";
}

int main()
{
    // Create an array of function pointers and initialize it with our function
    void (*functionArray[1])() = {myFunction};

    // Call the function in the array 5 times
    callFunction(5, functionArray[0]);

    return 0;
}
