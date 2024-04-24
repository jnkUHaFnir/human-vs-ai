#include <iostream>
#include <string>

class PrintLater
{
public:
    PrintLater(const std::string& str) : message(str) {}

    template<typename T>
    PrintLater& operator<<(T value)
    {
        buffer << value;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl)
    {
        os << pl.message << pl.buffer.str();
        return os;
    }

private:
    std::string message;
    std::stringstream buffer;
};

int main()
{
    int x = 10, y = 59;
    std::cout << PrintLater("Hello World") << x << y;
}
