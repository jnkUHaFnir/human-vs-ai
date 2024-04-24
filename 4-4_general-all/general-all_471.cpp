#include <iostream>
#include <string>

class PrintLater {
public:
    explicit PrintLater(std::string str) : msg(str) {}
    
    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl) {
        os << pl.msg;
        return os;
    }

    std::string str() const {
        return msg;
    }

private:
    std::string msg;
};

int main() {
    int x = 10, y = 59;

    PrintLater pl("Hello World");

    std::cout << pl << x << y << pl.str();

    return 0;
}
