#include <iostream>
#include <string>

std::string msg;

class PrintLater {
public:
    std::string str;
};

PrintLater printThisLater(std::string str)
{
    PrintLater pl;
    pl.str = str;
    return pl;
}

std::string printItNow()
{
    return msg;
}

std::ostream& operator<<(std::ostream& os, const PrintLater& pl)
{
    msg = pl.str;
    return os;
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow();

    return 0;
}
