#include <iostream>
#include <string>
#include <sstream>

class DeferredPrinter {
public:
    explicit DeferredPrinter(std::string str)
        : m_str(std::move(str)) {
    }

    friend std::ostream& operator<<(std::ostream& os, const DeferredPrinter& printer);

private:
    std::string m_str;
};

std::ostream& operator<<(std::ostream& os, const DeferredPrinter& printer) {
    return os << printer.m_str;
}

DeferredPrinter printThisLater(std::string str) {
    return DeferredPrinter(std::move(str));
}

int main() {
    int x = 10, y = 59;
    std::stringstream ss;
    ss << x << y;
    std::string result = ss.str();

    std::cout << printThisLater("Hello, World") << result;
}
