#include <iostream>
#include <string>
#include <sstream>

class DelayedOutputBuffer : public std::stringbuf
{
public:
    virtual int sync() override
    {
        std::cout << str();  // Print the stored string
        str("");  // Clear the buffer
        return 0;
    }
};

std::ostream& printThisLater(std::string str)
{
    static DelayedOutputBuffer buf;
    static std::ostream output(&buf);
    
    buf << str;  // Store the string in the buffer
    return output;
}

std::string printItNow()
{
    return ""; // Empty string as we are printing immediately
}

int main()
{
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow();
}
