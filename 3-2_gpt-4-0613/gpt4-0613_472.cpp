#include <iostream>
#include <sstream>

class printLaterType { };
static printLaterType printLater;
class printNowType { };
static printNowType printNow;

std::ostream& operator<<(std::ostream& os, printLaterType) {
    // Save the flags of 'os' and enable the manipulator flag.
    os.iword(0) = os.xalloc();
    return os;
}

std::ostream& operator<<(std::ostream& os, printNowType) {
    // Check if the manipulator flag is enabled.
    if (os.iword(0)) {
        // Reset the manipulator flag.
        os.iword(0) = 0;
        // Perform the delayed print operation.
        os << static_cast<std::ostringstream*>(os.pword(0))->str();
        // Reset the stringstream.
        static_cast<std::ostringstream*>(os.pword(0))->str("");
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const std::string& str) {
    if (os.iword(0)) {
        // If the manipulator is enabled, buffer the string to 'os' stringstream.
        if (!os.pword(0)) {
            os.pword(0) = new std::ostringstream();
        }
        *static_cast<std::ostringstream*>(os.pword(0)) << str;
    } else {
        // Otherwise, print the string to 'os'.
        os << str;
    }
    return os;
}

int main()
{
    int x = 10, y = 59;

    std::cout << printLater << "Hello, World" << x << y << printNow << std::endl;

    return 0;
}
