#include <iostream>
#include <string>

class PrintLater
{
public:
    PrintLater(std::string str) : msg(str) {}

    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl)
    {
        os << pl.msg;
        return os;
    }

private:
    std::string msg;
};

std::string printItNow()
{
    return "";
}

int main()
{
    int x = 10, y = 59;

    std::cout << PrintLater("Hello World") << x << y << printItNow();

    return 0;
}
