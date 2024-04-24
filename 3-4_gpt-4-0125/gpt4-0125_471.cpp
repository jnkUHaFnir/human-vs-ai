#include <iostream>
#include <string>
#include <sstream>

class DelayedPrinter {
public:
    DelayedPrinter() = default;

    std::ostream& print(std::ostream &os) const {
        if (!msg.empty()) {
            os << msg;
        }
        return os;
    }

    void setMessage(const std::string& str) {
        msg = str;
    }

private:
    std::string msg;
};

// Global instance (for simplicity; consider more elegant solutions for real applications)
DelayedPrinter delayedPrinter;

// For capturing the message to be printed later
std::ostream& printThisLater(std::ostream& os, const std::string& str) {
    delayedPrinter.setMessage(str);
    return os; // Just return the stream as is, no changes made
}

// For outputting the delayed message
std::ostream& printItNow(std::ostream& os) {
    return delayedPrinter.print(os);
}

// Helper functions to make it usable with <<
std::ostream& (*printThisLater(const std::string& str))(std::ostream& os) {
    return std::bind(printThisLater, std::placeholders::_1, str);
}

std::ostream& (*printItNow())(std::ostream& os) {
    return printItNow;
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello, World ") << x << " " << y << " " << printItNow();
}
