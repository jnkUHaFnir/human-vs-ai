#include <iostream>
#include <string>
#include <functional>

class DeferredPrinter {
public:
    void set(std::string str) {
        msg = str;
    }

    friend std::ostream& operator<<(std::ostream& os, const DeferredPrinter& printer) {
        return os << printer.msg;
    }
private:
    std::string msg;
};

DeferredPrinter def_printer;

// A manipulator that stores the string by reference and returns a std::ostream reference
std::ostream& printThisLater(std::ostream& os, const std::string& str) {
    def_printer.set(str);
    return os;
}

// Another manipulator that doesn't take any input and just prints the stored message
std::ostream& printItNow(std::ostream& os) {
    os << def_printer;
    return os;
}

// Overloads for the manipulators to be treated as stream objects
std::ostream& operator<<(std::ostream& os, std::ostream& (*func)(std::ostream&, const std::string&)) {
    return func(os, "");
}

std::ostream& operator<<(std::ostream& os, std::ostream& (*func)(std::ostream&)) {
    return func(os);
}

int main() {
    int x = 10, y = 59;

    std::cout << std::bind(printThisLater, std::placeholders::_1, "Hello World") << x << y << printItNow;
    return 0;
}
