#include <iostream>
#include <string>
#include <sstream>

std::stringstream msgStream;

std::ostream& printThisLater(const std::string& str)
{
    msgStream << str;
    return msgStream;
}

std::string printItNow()
{
    return msgStream.str();
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow() << std::endl;
}
Hello World1059Hello World
