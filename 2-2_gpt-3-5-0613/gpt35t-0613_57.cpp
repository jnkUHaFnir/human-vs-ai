#include <iostream>
using namespace std;

// Function declarations
void function1();
void function2();
void function3();

// Array of function pointers
void (*functionArray[])() = {function1, function2, function3};

// Recursive function to call function x times
void callFunctionXTimes(int remainingCalls)
{
    if (remainingCalls > 0)
    {
        // Choose a random function from the array and call it
        int randomIndex = rand() % (sizeof(functionArray) / sizeof(functionArray[0]));
        functionArray[randomIndex]();

        // Recursive call to continue calling functions
        callFunctionXTimes(remainingCalls - 1);
    }
}

// Sample functions
void function1()
{
    cout << "Function 1 called" << endl;
}

void function2()
{
    cout << "Function 2 called" << endl;
}

void function3()
{
    cout << "Function 3 called" << endl;
}

int main()
{
    int x = 5; // Number of times to call the functions
    callFunctionXTimes(x);

    return 0;
}
