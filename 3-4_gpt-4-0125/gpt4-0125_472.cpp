#include <iostream>
#include <string>
#include <functional>

// Forward declaration for our manipulators
std::ostream& printThisLater(std::ostream& os, const std::string& str);
std::ostream& printItNow(std::ostream& os);

// Registering manipulators with iostream
namespace std {
    ostream& operator<<(ostream& os, function<ostream& (ostream&)> func) {
        return func(os);
    }
}
std::string global_msg;

// Manipulator for storing a string
std::ostream& printThisLater(std::ostream& os, const std::string& str) {
    global_msg = str;
    return os;
}

// Manipulator for printing the stored string
std::ostream& printItNow(std::ostream& os) {
    os << global_msg;
    return os;
}
std::function<std::ostream&(std::ostream&)> printThisLater(const std::string& str) {
    return std::bind(&::printThisLater, std::placeholders::_1, str);
}

std::function<std::ostream&(std::ostream&)> printItNow() {
    return std::bind(&::printItNow, std::placeholders::_1);
}
#include <iostream>
#include <string>
#include <functional>

using namespace std;

string global_msg;

ostream& printThisLaterImpl(ostream& os, const string& str) {
    global_msg = str;
    return os;
}

ostream& printItNowImpl(ostream& os) {
    os << global_msg;
    return os;
}

function<ostream&(ostream&)> printThisLater(const string& str) {
    return bind(&printThisLaterImpl, placeholders::_1, str);
}

function<ostream&(ostream&)> printItNow() {
    return bind(&printItNowImpl, placeholders::_1);
}

namespace std {
    ostream& operator<<(ostream& os, function<ostream& (ostream&)> func) {
        return func(os);
    }
}

int main() {
    int x = 10, y = 59;
    cout << printThisLater("Hello, World! ") << x << " " << y << " " << printItNow();
}
