#include <iostream>

void myFunction() {
    std::cout << "Function Called" << std::endl;
}

template<int N>
struct Repeat : Repeat<N-1> {
    Repeat() {
        myFunction();
    }
};

template<>
struct Repeat<0> {}; // Specialization to end recursion.

int main() {
    Repeat<5> callMyFunctionFiveTimes; // This will call myFunction() 5 times at compile time.
    return 0;
}
