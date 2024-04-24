#include <iostream>
#include <string>
#include <sstream>

class PrintLater {
public:
    PrintLater() : later("") {}
    
    std::ostream& printThisLater(std::string str) {
        later = str;
        return *this;
    }

    std::string printItNow() const {
        return later;
    }

private:
    std::string later;
};

// Custom manipulator function to interact with iostream
std::ostream& printThisLater(std::ostream& os, const std::string& str) {
    os.pword(0) = new std::string(str);
    return os;
}

// Custom manipulator function to interact with iostream
std::ostream& printItNow(std::ostream& os) {
    std::string *saved = static_cast<std::string*>(os.pword(0));
    if (saved) {
        os << *saved;
        delete saved;
        os.pword(0) = nullptr;
    }
    return os;
}

int main()
{
    int x = 10, y = 59;

    PrintLater pl;
    std::cout << std::bind(printThisLater, std::placeholders::_1, "Hello World") << x << y << printItNow;

    return 0;
}
