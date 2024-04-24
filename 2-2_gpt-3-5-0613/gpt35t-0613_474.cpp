#include <iostream>
#include <string>
#include <sstream>

class DelayedOutput
{
public:
    DelayedOutput(const std::string& message) : message(message), oss() {}

    template <typename T>
    DelayedOutput& operator<<(const T& value)
    {
        oss << value;
        return *this;
    }

    ~DelayedOutput()
    {
        std::cout << message << oss.str();
    }

private:
    std::string message;
    std::ostringstream oss;
};

DelayedOutput printThisLater(const std::string& str)
{
    return DelayedOutput(str);
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y;
}
