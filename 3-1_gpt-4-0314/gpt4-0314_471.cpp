#include <iostream>
#include <string>
#include <sstream>

class PrintLater
{
public:
    explicit PrintLater(const std::string &str) : _str(str) {}

    friend std::ostream &operator<<(std::ostream &os, const PrintLater &printLater)
    {
        os << printLater._str;
        return os;
    }

    void store(std::ostream &os) const
    {
        os << _str;
    }

private:
    std::string _str;
};

struct PrintLaterTag {};

std::ostream &operator<<(std::ostream &os, const PrintLaterTag &)
{
    return os;
}

class PrintItNow
{
public:
    /* Empty constructor */
    PrintItNow() = default;

    friend std::ostream &operator<<(std::ostream &os, const PrintItNow &printItNow)
    {
        os << _stream.str();
        return os;
    }

    void recall(const PrintLater &printLater)
    {
        printLater.store(_stream);
    }

private:
    std::stringstream _stream;
};

PrintLater printThisLater(const std::string &str)
{
    return PrintLater(str);
}

PrintItNow printItNow()
{
    return PrintItNow();
}

int main()
{
    int x = 10, y = 59;

    PrintLater pl = printThisLater("Hello World");
    PrintItNow pi;
    pi.recall(pl);
    std::cout << pl << PrintLaterTag() << x << y << pi;

    return 0;
}
