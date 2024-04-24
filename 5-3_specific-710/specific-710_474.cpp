#include <iostream>
#include <string>

class PrintLater
{
private:
    std::string msg;

public:
    PrintLater(std::string str) : msg(str) {}

    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl)
    {
        os << pl.msg;
        return os;
    }
};

class PrintNow
{
private:
    std::string msg;

public:
    PrintNow(std::string str) : msg(str) {}

    friend std::ostream& operator<<(std::ostream& os, const PrintNow& pn)
    {
        os << pn.msg;
        return os;
    }
};

PrintLater printThisLater(std::string str)
{
    return PrintLater(str);
}

PrintNow printItNow(std::string str)
{
    return PrintNow(str);
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow("!");
    
    return 0;
}
