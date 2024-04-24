#include <iostream>
#include <string>

class PrintLater
{
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

int main()
{
    int x = 10, y = 59;

    std::cout << PrintLater("Hello, World ") << x << y << " " << PrintLater("Printed later") << std::endl;

    return 0;
}
