#include <iostream>
#include <string>
#include <sstream>

class DeferredPrinter {
private:
    std::stringstream buffer;
    
public:
    DeferredPrinter& operator<<(const std::string& str) {
        buffer << str;
        return *this;
    }

    // We provide overloads for << with commonly used types.
    // You would ideally add overloads for other types as needed.
    DeferredPrinter& operator<<(int num) {
        buffer << num;
        return *this;
    }

    DeferredPrinter& operator<<(double num) {
        buffer << num;
        return *this;
    }

    // You can provide a directly callable print function as well.
    void print(std::ostream& os) {
        os << buffer.str();
        buffer.clear(); // Clear the contents of the buffer
        buffer.str(std::string()); // Reset the underlying string as well
    }

    // Define a friend operator to easily insert this manipulator into streams
    friend std::ostream& operator<<(std::ostream& os, DeferredPrinter& dp) {
        dp.print(os);
        return os;
    }
};

// Manipulator to append data to the deferred printer
DeferredPrinter& printThisLater(DeferredPrinter& dp, const std::string& str) {
    dp << str;
    return dp;
}

// Global instance of our DeferredPrinter
DeferredPrinter deferredPrinter;

int main() {
    int x = 10, y = 59;

    // Using our custom manipulators
    std::cout << printThisLater(deferredPrinter, "Hello, World ") << x << " " << y << " " << deferredPrinter;
}
