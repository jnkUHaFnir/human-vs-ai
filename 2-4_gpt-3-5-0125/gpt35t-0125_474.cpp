#include <iostream>
#include <string>
#include <sstream>

class PrintLaterBuffer : public std::stringbuf
{
public:
    int sync() override
    {
        std::cout << str();
        str("");
        return 0;
    }
};

class PrintLaterStream : public std::ostream
{
public:
    PrintLaterStream() : std::ostream(&buffer) {}

    std::stringbuf* rdbuf()
    {
        return &buffer;
    }

private:
    PrintLaterBuffer buffer;
};

PrintLaterStream printLaterStream;

std::ostream& printThisLater(const std::string& str)
{
    static_cast<PrintLaterBuffer*>(printLaterStream.rdbuf())->sputn(str.c_str(), str.size());
    return printLaterStream;
}

std::string printItNow()
{
    return "";
}

int main()
{
    int x = 10, y = 59;

    printThisLater("Hello World") << x << y << printItNow();
}
