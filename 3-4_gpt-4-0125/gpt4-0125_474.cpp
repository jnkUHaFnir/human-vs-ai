#include <iostream>
#include <string>
#include <functional>

// Use a global variable to store the deferred message.
// Note: Globals are generally discouraged; consider better state management for production code.
std::string msg;

std::ostream& printThisLater(std::ostream& os) {
    // Capture the deferred message into the ostream's state via a custom manipulator.
    // Here, we only return the stream without manipulating it directly.
    return os;
}

std::ostream& printItNow(std::ostream& os) {
    // This custom manipulator prints the deferred message.
    os << msg;
    // Clear the message after printing.
    msg.clear();
    return os;
}

// Function to help in using the global deferred message setup
std::ostream& deferMessage(std::ostream& os, const std::string& s) {
    // Set the global deferred message.
    msg = s;
    // Return a custom manipulator that does nothing by itself but allows chaining.
    return os << printThisLater;
}

int main() {
    int x = 10, y = 59;

    // Example usage
    std::cout << deferMessage(std::cout, "Hello World") << x << ' ' << y << printItNow;
}
