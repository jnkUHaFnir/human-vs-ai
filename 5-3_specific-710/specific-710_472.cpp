#include <iostream>
#include <string>
#include <sstream>

std::string msg;

class DelayedOutput : public std::stringbuf
{
public:
    virtual int sync()
    {
        msg = str();
        str("");
        return 0;
    }
};

std::ostream& printThisLater(const std::string& str)
{
    static DelayedOutput buffer;
    std::ostream output(&buffer);
    output << str;
    return output;
}

std::string printItNow()
{
    return msg;
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow();

    return 0;
}
