#include <iostream>
#include <string>
#include <sstream>

class DelayedOutput {
private:
    std::ostringstream oss;

public:
    DelayedOutput& operator<<(const std::string& str) {
        oss << str;
        return *this;
    }

    template <typename T>
    DelayedOutput& operator<<(const T& val) {
        oss << val;
        return *this;
    }

    std::string str() const {
        return oss.str();
    }
};

DelayedOutput msg;

DelayedOutput& printThisLater(std::string str) {
    msg << str;
    return msg;
}

std::string printItNow() {
    return msg.str();
}

int main() {
    int x = 10, y = 59;
    
    std::cout << printThisLater("Hello, World") << x << y << printItNow();
}
