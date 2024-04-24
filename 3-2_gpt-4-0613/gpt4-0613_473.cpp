#include <iostream>
#include <string>
#include <functional>

std::function<void(std::ostream&)> printer;

std::ostream& printThisLater(std::ostream& os, std::string str)
{
    printer = [str](std::ostream& os)->void {os << str;};
    return os;
}

std::ostream& printItNow(std::ostream& os)
{
    printer(os);
    return os;
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater(std::cout, "Hello, World") << x << y << printItNow(std::cout);
}
