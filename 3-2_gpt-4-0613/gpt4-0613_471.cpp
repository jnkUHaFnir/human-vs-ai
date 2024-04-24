#include <iostream>
#include <string>
#include <sstream>

class printLater {
    std::string _value;

public:
    printLater(std::string str): _value(str) {}
    friend std::ostream& operator<<(std::ostream& os, const printLater& pl) {
        return os << pl._value;
    }
};

class printNow {
    std::string _value;

public:
    printNow(std::stringstream& ss) { _value = ss.str(); ss.str(""); ss.clear(); }
    friend std::ostream& operator<<(std::ostream& os, const printNow& pn) {
        return os << pn._value;
    }
};

int main()
{
    int x = 10, y = 20;
    std::stringstream ss;

    // Store "Hello, World!" for later
    ss << printLater("Hello, World!");

    // Immediately output x and y
    std::cout << x << ", " << y << ", ";

    // Now print that stored message
    std::cout << printNow(ss) << std::endl;

    return 0;
}
#include <iostream>
#include <string>
#include <sstream>

class DelayedPrinter {
    std::stringstream ss;
public:
    DelayedPrinter& operator<<(const std::string& str) {
        ss << str;
        return *this;
    }
    void print(std::ostream& os) {
        os << ss.str();
        ss.str(""); // clear the buffer
    }
};

int main()
{
    int x = 10, y = 20;
    DelayedPrinter printer;

    printer << "Hello, World!";
    std::cout << x << ", " << y << ", ";
    printer.print(std::cout);

    return 0;
}
