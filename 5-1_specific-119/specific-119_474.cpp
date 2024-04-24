#include <iostream>
#include <string>

class PrintLater {
private:
    std::string msg;

public:
    PrintLater(const std::string& str) : msg(str) {}

    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl) {
        os << pl.msg;
        return os;
    }

    std::string getMsg() const {
        return msg;
    }
};

PrintLater printThisLater(const std::string& str) {
    return PrintLater(str);
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello, World") << x << y << printThisLater(" - will print later").getMsg() << std::endl;

    return 0;
}
