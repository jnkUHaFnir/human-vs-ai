#include <iostream>
#include <string>

class DelayedPrint
{
public:
    DelayedPrint(const std::string& str) : msg(str) {}

    friend std::ostream& operator<<(std::ostream& os, const DelayedPrint& dp)
    {
        return os << dp.msg;
    }

private:
    std::string msg;
};

DelayedPrint printThisLater(const std::string& str)
{
    return DelayedPrint(str);
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printThisLater(" - Foo Bar") << "\n";

    std::cout << printThisLater("More delayed output") << printThisLater(" - And some more") << "\n";
}