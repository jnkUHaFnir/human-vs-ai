#include <iostream>
#include <string>
#include <sstream>

class DelayedPrintBuffer : public std::stringbuf {
public:
    virtual int sync() {
        // Output the stored string to the console
        std::cout << str();

        // Clear the buffer
        str("");
        return 0;
    }
};

// Create a custom output stream that uses the DelayedPrintBuffer
class DelayedPrintStream : public std::ostream {
public:
    DelayedPrintStream() : std::ostream(&buf) {}
private:
    DelayedPrintBuffer buf;
};

// A helper function to create the delayed print stream
DelayedPrintStream printThisLater(const std::string& str) {
    DelayedPrintStream stream;
    stream << str;
    return stream;
}

// A helper function to trigger the delayed print
std::string printItNow() {
    return "";
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow();

    // Output: Hello World1059

    return 0;
}