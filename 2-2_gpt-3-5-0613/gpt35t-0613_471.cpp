#include <iostream>
#include <string>

class PrintLater {
public:
    PrintLater(const std::string& str) : msg(str) {}
    
    template <typename T>
    PrintLater operator<<(const T& value) {
        std::cout << msg; // Print the stored message
        return PrintLater(""); // Return a new instance to continue chaining
    }
    
private:
    std::string msg;
};

PrintLater printThisLater(const std::string& str)
{
    return PrintLater(str);
}

std::string printItNow()
{
    return "";
}

int main()
{
    int x = 10, y = 59;
    
    std::cout << printThisLater("Hello, World") << " " << x << " " << y << printItNow();
    
    return 0;
}
Hello, World 10 59
