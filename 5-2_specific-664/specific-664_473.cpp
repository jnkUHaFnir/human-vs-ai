#include <iostream>
#include <streambuf>
#include <string>
#include <memory>

// Custom stream buffer to store the string
class DelayedStringBuffer : public std::stringbuf {
public:
    std::string getStoredString() {
        return str();
    }
};

// Custom output stream class
class DelayedStringStream : public std::ostream {
public:
    DelayedStringStream() : std::ostream(&buffer), buffer({}) {}
    
    std::string getString() {
        return buffer.getStoredString();
    }
    
private:
    DelayedStringBuffer buffer;
};

DelayedStringStream delayedStream;

// Function to store string for later
std::ostream& printThisLater(const std::string& str) {
    delayedStream << str;
    return delayedStream;
}

// Function to immediately print stored string
std::string printItNow() {
    return delayedStream.getString();
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World: ") << x << " " << y << " " << printItNow() << std::endl;

    return 0;
}
