#include <iostream>
#include <string>
#include <sstream>

class PrintLaterBuffer : public std::streambuf {
public:
    virtual int overflow(int c) {
        if (c != EOF) {
            oss << (char) c;
            return c;
        }
        else {
            return EOF;
        }
    }

    std::string getOutput() const {
        return oss.str();
    }

private:
    std::ostringstream oss;
};

PrintLaterBuffer printLaterBuffer;
std::ostream printLaterStream(&printLaterBuffer);

std::ostringstream printNowStream;

std::ostream& printThisLater(std::string str) {
    printLaterStream.clear();
    printLaterBuffer.getOutput().clear();
    printLaterStream << str;
    return printLaterStream;
}

std::string printItNow() {
    return printNowStream.str();
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y;
    printNowStream << printItNow() << printLaterBuffer.getOutput();
    std::cout << printNowStream.str();
}