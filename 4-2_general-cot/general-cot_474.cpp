#include <iostream>
#include <string>
#include <streambuf>
#include <sstream>

class DelayedOutputBuffer : public std::stringbuf {
private:
    std::string delayedOutput;

public:
    int sync() override {
        std::cout << delayedOutput;
        return 0;
    }
    
    DelayedOutputBuffer& operator<<(const std::string& str) {
        delayedOutput += str;
        return *this;
    }
};

DelayedOutputBuffer printLaterBuffer;

std::ostream printThisLater(const std::string& str) {
    printLaterBuffer << str;
    return std::ostream(&printLaterBuffer);
}

std::string printItNow() {
    return printLaterBuffer.str();
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World");
    std::cout << x << y << printItNow();
}
