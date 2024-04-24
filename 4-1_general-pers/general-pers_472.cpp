#include <iostream>
#include <string>

class PrintLater
{
public:
    PrintLater& operator<<(const std::string& str)
    {
        msg += str;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl)
    {
        os << pl.msg;
        return os;
    }

private:
    std::string msg;
};

PrintLater printThisLater(const std::string& str)
{
    PrintLater pl;
    pl << str;
    return pl;
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y;
}
