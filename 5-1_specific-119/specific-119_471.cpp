#include <iostream>
#include <sstream>
#include <string>

// Custom stream buffer class to store the string
class DelayedOutputBuffer : public std::stringbuf {
public:
    virtual int sync() {
        // Do nothing when sync is called to delay the output
        return 0;
    }

    std::string getOutput() {
        return str();
    }
};

// Stream manipulator to set the delayed output
class DelayedOutputManip {
public:
    DelayedOutputManip(const std::string& str) : value(str) {}

    friend std::ostream& operator<<(std::ostream& os, const DelayedOutputManip& dom) {
        static DelayedOutputBuffer buf;
        os.basic_ios<char>::rdbuf(&buf);
        buf.str(dom.value);
        return os;
    }

private:
    std::string value;
};

// Function to create the delayed output manipulator
inline DelayedOutputManip printThisLater(const std::string& str) {
    return DelayedOutputManip(str);
}

// Function to print the stored output immediately
std::string printItNow() {
    static DelayedOutputBuffer buf;
    return buf.getOutput();
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow();
    // Output will be delayed until printItNow is called
    // To print immediately, call printItNow after the desired point of output
    std::cout << printItNow(); // Print the stored string immediately

    return 0;
}
