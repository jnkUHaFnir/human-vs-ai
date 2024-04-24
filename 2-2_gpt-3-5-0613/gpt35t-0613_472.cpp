#include <iostream>
#include <string>

class DelayedStream {
public:
    DelayedStream(const std::string& str) : message(str) {}

    DelayedStream& operator<<(const std::string& str) {
        output += str;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const DelayedStream& ds) {
        os << ds.output;
        return os;
    }

private:
    std::string message;
    std::string output;
};

DelayedStream printThisLater(const std::string& str) {
    return DelayedStream(str);
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello, World") << x << y << printThisLater("This is printed later") << std::endl;

    return 0;
}
