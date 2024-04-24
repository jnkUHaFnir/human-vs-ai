#include <iostream>
#include <string>
#include <functional>

class PrintLater
{
public:
    explicit PrintLater(const std::string& str) : msg_(str) {}

    // Overload the output stream operator
    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl)
    {
        os << pl.msg_;
        return os;
    }

private:
    std::string msg_;
};

std::ostream& printThisLater(const std::string& str, std::ostream& os = std::cout)
{
    std::function<void()> printLater = [str, &os]() {
        os << str;
    };
    os.pword(os.xalloc()) = reinterpret_cast<long>(&printLater);
    return os;
}

std::ostream& printItNow(std::ostream& os)
{
    auto printLater = reinterpret_cast<std::function<void()>*>(os.pword(os.xalloc()));
    if (printLater && *printLater) {
        (*printLater)();
    }
    return os;
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow << std::endl;

    return 0;
}
