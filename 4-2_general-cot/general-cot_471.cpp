#include <iostream>
#include <string>

class DelayedOutput {
public:
    DelayedOutput& operator<<(const std::string& str) {
        message += str;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const DelayedOutput& delayedOutput) {
        return os << delayedOutput.message;
    }

private:
    std::string message;
};

DelayedOutput printThisLater(const std::string& str) {
    DelayedOutput delayedOutput;
    delayedOutput << str;
    return delayedOutput;
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello, World ") << x << y; // Output is delayed

    std::cout << "Before printItNow() "; // To show delay

    std::cout << printItNow(); // Now print the delayed message

    return 0;
}
