#include <iostream>
#include <string>

class PrintLater {
public:
    explicit PrintLater(std::string str) : msg(str) {}

    friend std::ostream& operator<<(std::ostream& os, const PrintLater& pl) {
        return os << pl.msg;
    }

    std::string getMsg() const {
        return msg;
    }

private:
    std::string msg;
};

int main() {
    int x = 10, y = 59;

    std::cout << PrintLater("Hello World") << x << y << PrintLater("Later message").getMsg();

    return 0;
}
