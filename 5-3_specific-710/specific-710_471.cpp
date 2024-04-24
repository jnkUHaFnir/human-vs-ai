#include <iostream>
#include <string>
#include <sstream>

std::stringstream msgStream;

// Custom manipulator to store the string in the stringstream
std::ostream& printThisLater(const std::string& str)
{
    msgStream << str;
    return msgStream;
}

// Function to retrieve the stored message
std::string printItNow()
{
    return msgStream.str();
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow();
}
