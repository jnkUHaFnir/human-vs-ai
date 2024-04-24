#include <iostream>
#include <sstream>
#include <string>

class DelayedOutputBuffer : public std::stringbuf
{
public:
    std::string getOutput() const { return str(); }
};

std::ostream& printThisLater(const std::string& str, DelayedOutputBuffer& buffer)
{
    buffer.str(str);
    return buffer;
}

std::string printItNow(const DelayedOutputBuffer& buffer)
{
    return buffer.getOutput();
}

int main()
{
    int x = 10, y = 59;
    DelayedOutputBuffer buffer;

    std::cout << printThisLater("Hello World", buffer) << x << y << printItNow(buffer);
}
