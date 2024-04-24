#include <iostream>
#include <string>

class PrintBuffer
{
public:
    PrintBuffer& operator<<(const std::string& str)
    {
        msg += str;
        return *this;
    }

    std::string getData() const
    {
        return msg;
    }

private:
    std::string msg;
};

PrintBuffer printThisLater(const std::string& str)
{
    PrintBuffer buffer;
    buffer << str;
    return buffer;
}

std::string printItNow()
{
    // Do any additional processing if needed
    return "";
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow().getData();

    return 0;
}
