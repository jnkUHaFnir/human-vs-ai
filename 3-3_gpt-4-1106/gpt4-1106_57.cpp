void foo() {
    // Your function implementation here
}

int main() {
    foo(); // Call 1
    foo(); // Call 2
    foo(); // Call 3
    foo(); // Call 4
    foo(); // Call 5
    return 0;
}
#include <iostream>

template <int N>
struct CallFunction {
    static void call() {
        foo();
        CallFunction<N - 1>::call(); // Recursive template instantiation
    }
};

template <>
struct CallFunction<0> {
    static void call() {} // Termination of recursion
};

void foo() {
    std::cout << "Function called" << std::endl;
}

int main() {
    const int times = 5;
    CallFunction<times>::call(); // Calls 'foo' 5 times
    return 0;
}
