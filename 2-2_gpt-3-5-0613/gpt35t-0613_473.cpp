#include <iostream>
#include <string>

class PrintThisLater {
private:
    std::string message;

public:
    PrintThisLater(std::string str) : message(str) {}

    friend std::ostream& operator<<(std::ostream& os, const PrintThisLater& obj) {
        os << obj.message;
        return os;
    }
};

int main() {
    int x = 10, y = 59;

    std::cout << PrintThisLater("Hello, World") << x << y << std::endl;

    return 0;
}
