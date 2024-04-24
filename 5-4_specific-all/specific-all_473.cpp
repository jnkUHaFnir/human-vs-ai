#include <iostream>
#include <string>

class PrintLater {
public:
    PrintLater& operator<<(const std::string& str) {
        msg += str;
        return *this;
    }

    PrintLater& operator<<(int val) {
        msg += std::to_string(val);
        return *this;
    }

    std::string operator()() {
        return msg;
    }

private:
    std::string msg;
};

int main() {
    PrintLater printLater;

    int x = 10, y = 59;

    printLater << "Hello, World" << x << y;
    
    std::cout << printLater() << std::endl;

    return 0;
}
