#include <iostream>
#include <string>

class PrintLater {
public:
    PrintLater(const std::string& str) : msg(str) {}

    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl) {
        return os << pl.msg;
    }

    std::string getMessage() const {
        return msg;
    }

private:
    std::string msg;
};

int main()
{
    int x = 10, y = 59;

    std::cout << PrintLater("Hello World") << x << y << PrintLater(" This is printed now") << std::endl;

    return 0;
}
