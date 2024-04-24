#include <iostream>
#include <string>

class DelayedPrint {
private:
    std::string msg;

public:
    DelayedPrint& operator<<(const std::string& str) {
        msg += str;
        return *this;
    }

    DelayedPrint& operator<<(int value) {
        msg += std::to_string(value);
        return *this;
    }

    void print() {
        std::cout << msg;
    }
};

DelayedPrint printThisLater(const std::string& str) {
    DelayedPrint dp;
    dp << str;
    return dp;
}

int main() {
    int x = 10, y = 59;

    printThisLater("Hello, World") << x << y;
    // Other parts of the program

    printThisLater(" This is delayed").print();
    std::cout << " This is immediate\n";

    return 0;
}
