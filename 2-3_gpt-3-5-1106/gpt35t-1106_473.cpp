#include <iostream>
#include <string>

class PrintLater
{
public:
    PrintLater(const std::string& str) : message(str) {}
    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl)
    {
        os << pl.message;
        return os;
    }

private:
    std::string message;
};

std::string printItNow(const std::string& str)
{
    return str;
}

int main()
{
    int x = 10, y = 59;

    std::cout << PrintLater("Hello World") << x << y << printItNow("hello");
}
