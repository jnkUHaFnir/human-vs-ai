#include <iostream>
#include <string>

class PrintLater {
public:
    explicit PrintLater(const std::string& str) : msg(str) {}
    
    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl) {
        os << pl.msg;
        return os;
    }
    
    std::string str() const {
        return msg;
    }
    
private:
    std::string msg;
};

PrintLater printThisLater(const std::string& str) {
    return PrintLater(str);
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << std::endl;
    std::cout << "Printed later: " << printThisLater("Later text").str() << std::endl;
    
    return 0;
}
