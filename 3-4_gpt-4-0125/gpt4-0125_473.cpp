#include <iostream>
#include <sstream> // Required for std::stringstream
#include <string>

// Forward declaration
std::ostream& printItNow(std::ostream& os);

// A class to hold the string until it needs to be printed
class DeferredPrinter {
private:
    std::string message;

    // Make printItNow a friend function so it can access private members
    friend std::ostream& printItNow(std::ostream& os);

public:
    DeferredPrinter(const std::string& msg) : message(msg) {}
};

// This function returns an object that holds the string to be printed later
DeferredPrinter printThisLater(const std::string& str) {
    return DeferredPrinter(str);
}

// This is an overloaded operator<< to handle the DeferredPrinter class
std::ostream& operator<<(std::ostream& os, const DeferredPrinter& dp) {
    // For now, do nothing. Just return the stream as is.
    // The actual printing will happen in printItNow function.
    return os;
}

// This is a manipulator function that actually triggers the printing of the stored string
std::ostream& printItNow(std::ostream& os) {
    // Using the internals of ostream to access the custom string stored in pword
    auto& deferPrinter = *static_cast<DeferredPrinter*>(os.pword(0));
    if (!deferPrinter.message.empty()) {
        os << deferPrinter.message;
        // Clear the message once printed to avoid reprinting if printItNow is called again
        deferPrinter.message.clear();
    }
    return os;
}

int main() {
    int x = 10, y = 59;
    std::ostringstream buffer; // Using a stringstream to simulate output

    // Store the deferredPrinter object in pword for later access
    auto& deferredPrinter = buffer.pword(0) = new DeferredPrinter("Hello, World");

    // Simulate the desired output
    buffer << printThisLater("Hello, World") << x << " " << y << printItNow;

    // Cleanup
    delete static_cast<DeferredPrinter*>(deferredPrinter);

    std::cout << buffer.str(); // Finally output the result
}
