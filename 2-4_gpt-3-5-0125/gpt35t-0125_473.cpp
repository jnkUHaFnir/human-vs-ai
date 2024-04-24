#include <iostream>
#include <string>

class PrintThisLater {
public:
    PrintThisLater& operator<<(const std::string& str) {
        msg = str;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const PrintThisLater& ptl) {
        return os;
    }

    std::string printItNow() {
        return msg;
    }

private:
    std::string msg;
};

int main() {
    int x = 10, y = 59;

    PrintThisLater ptl;
    std::cout << ptl << "Hello World" << x << y << ptl.printItNow();
    
    return 0;
}
