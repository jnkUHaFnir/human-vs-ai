#include <iostream>
#include <string>
#include <sstream>

std::ostringstream delayedOutput;

class PrintThisLater
{
public:
    explicit PrintThisLater(std::string str) : msg(str) {}

    friend std::ostream& operator<<(std::ostream& os, const PrintThisLater& obj)
    {
        delayedOutput << obj.msg;
        return os;
    }

private:
    std::string msg;
};

PrintThisLater printThisLater(std::string str)
{
    return PrintThisLater(str);
}

std::string printItNow()
{
    return delayedOutput.str();
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello, World ") << x << y << printItNow();

    return 0;
}
