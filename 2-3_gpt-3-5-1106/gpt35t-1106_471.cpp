#include <iostream>
#include <string>

class PrintThisLater {
public:
    PrintThisLater(std::string str) : msg(str) { }

    friend std::ostream& operator<<(std::ostream& os, const PrintThisLater& printThisLater) {
        os << printThisLater.msg; 
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

    std::cout << PrintThisLater("Hello World") << x << y << PrintThisLater(" This will be printed now");
}
