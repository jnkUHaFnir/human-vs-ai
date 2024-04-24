#include <iostream>
#include <string>
#include <sstream>

std::ostringstream delayedStream;

std::ostringstream& printThisLater(std::string str)
{
    delayedStream << str;
    return delayedStream;
}

std::string printItNow()
{
    return delayedStream.str();
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World ").str() << x << " " << y << printItNow();
}
