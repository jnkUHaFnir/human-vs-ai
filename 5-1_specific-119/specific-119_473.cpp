#include <iostream>
#include <string>

class PrintLater
{
public:
    explicit PrintLater(std::string str) : msg(str) {}
    
    std::string getMessage() const { return msg; }

private:
    std::string msg;
};

class PrintNow
{
public:
    explicit PrintNow(std::string str) : msg(str) {}
    
    friend std::ostream& operator<<(std::ostream& os, const PrintNow& pn);

private:
    std::string msg;
};

std::string global_str; // To store the string for later printing

std::ostream& operator<<(std::ostream& os, const PrintLater& pl)
{
    global_str = pl.getMessage();
    return os;
}

std::ostream& operator<<(std::ostream& os, const PrintNow& pn)
{
    return os << global_str << pn.msg;
}

int main()
{
    int x = 10, y = 59;

    std::cout << PrintLater("Hello, World") << x << y << PrintNow(" - This is printed now\n");
}
