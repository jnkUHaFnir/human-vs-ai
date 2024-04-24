#include <iostream>
#include <string>
#include <functional>
#include <vector>

// A helper class to store deferred messages.
class DeferredPrinter {
public:
    // Add a message to be printed later.
    void add(const std::string& msg) {
        deferredMessages.emplace_back(msg);
    }

    // Print all stored messages.
    void printNow(std::ostream& os) {
        for (const auto& msg : deferredMessages) {
            os << msg;
        }
        deferredMessages.clear();
    }

private:
    std::vector<std::string> deferredMessages;
};

// Global instance of our helper (not ideal, but for demo purposes).
DeferredPrinter globalDeferredPrinter;

// A manipulator function to add a string to be deferred.
std::ostream& printThisLater(std::ostream& os, const std::string& str) {
    globalDeferredPrinter.add(str);
    return os;
}

// Another manipulator function to print all deferred strings.
std::ostream& printItNow(std::ostream& os) {
    globalDeferredPrinter.printNow(os);
    return os;
}

// Function to create a custom manipulator with a parameter.
std::function<std::ostream&(std::ostream&)> printThisLater(const std::string& str) {
    return std::bind(printThisLater, std::placeholders::_1, str);
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello, World ") << x << " " << y << " " << printItNow();
    return 0;
}
