#include <iostream>
#include <string>

class DelayedPrint
{
public:
    DelayedPrint& operator<<(const std::string& str)
    {
        msg += str;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const DelayedPrint& dp)
    {
        return os << dp.msg;
    }

private:
    std::string msg;
};

DelayedPrint printThisLater(const std::string& str)
{    
    DelayedPrint dp;
    dp << str;
    return dp;
}

std::string printItNow()
{
    return "";
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow();
    return 0;
}
