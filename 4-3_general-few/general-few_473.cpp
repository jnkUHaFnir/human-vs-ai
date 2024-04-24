#include <iostream>
#include <string>

class DelayedPrint
{
private:
    std::string msg;

public:
    DelayedPrint& operator<<(const std::string& str)
    {
        msg = str;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const DelayedPrint& dp)
    {
        os << dp.msg;
        return os;
    }
};

DelayedPrint printThisLater;

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater << "Hello, World" << x << y << printThisLater;
    
    return 0;
}
