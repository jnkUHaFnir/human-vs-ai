#include <iostream>
#include <string>
#include <sstream>

// This class holds the string until you want to print it
class PrintLater {
public:
    PrintLater() : later(), activated(false) {}

    // Overloaded operator to capture the string
    void operator()(const std::string& str) {
        later << str;
        activated = true; // Indicate that there's something to print later
    }

    // Friend operator to handle "printItNow" manipulator
    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl) {
        if (pl.activated) { // If there is something to print
            os << pl.later.str(); // Send it to the output stream
        }
        return os;
    }

private:
    std::stringstream later;
    mutable bool activated; // Need mutable because << operator is const
};

// Instantiating the "PrintLater" class
PrintLater printThisLater;

// Custom manipulator that will trigger the printing
std::ostream& printItNow(std::ostream& os) {
    os << printThisLater;
    return os;
}

int main()
{
    int x = 10, y = 59;

    // Using lambda to overload << with our PrintLater instance
    std::cout << [&](const std::string& str) -> std::ostream& {
        printThisLater(str);
        return std::cout;
    };

    // Now you can use standard << operator chaining
    std::cout << "Hello World" << x << y << printItNow;
}
