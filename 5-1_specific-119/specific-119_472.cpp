#include <iostream>
#include <string>

class PrintLater {
public:
    PrintLater& operator<<(const std::string& str) {
        msg = str;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl) {
        return os << pl.msg;
    }

private:
    std::string msg;
};

PrintLater printThisLater() {
    return PrintLater();
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater() << "Hello, World" << x << y << printThisLater();
    return 0;
}
