#include <iostream>
#include <string>

class DelayedOutput {
private:
    std::string message;

public:
    DelayedOutput& operator<<(const std::string& str) {
        message += str;
        return *this;
    }

    DelayedOutput& operator<<(int num) {
        message += std::to_string(num);
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const DelayedOutput& output) {
        os << output.message;
        return os;
    }
};

DelayedOutput printThisLater(const std::string& str) {
    DelayedOutput output;
    output << str;
    return output;
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y;
    return 0;
}
