#include <iostream>
#include <string>
#include <sstream>

class DelayedStringBuffer : public std::stringbuf {
public:
    int sync() override {
        // Do nothing on sync to delay printing
        return 0;
    }
};

class DelayedStringStream : public std::ostream {
public:
    DelayedStringStream(std::string& message) : std::ostream(&buffer), buffer() {
        buffer.str(message);
    }

    std::string str() {
        return buffer.str();
    }

private:
    DelayedStringBuffer buffer;
};

std::string msg;

DelayedStringStream printThisLater(std::string str) {
    msg = str;
    return DelayedStringStream(msg);
}

std::string printItNow() {
    return msg;
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World").str() << x << y << printItNow();
}
