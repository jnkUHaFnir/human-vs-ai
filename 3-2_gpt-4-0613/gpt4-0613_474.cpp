#include <iostream>
#include <string>

class Printer {
public:
    Printer() : stored(), storaged(false) {}
    Printer(const std::string& str) : stored(str), storaged(false) {}

    friend std::ostream& operator<<(std::ostream& os, const Printer& p) {
        if (!p.storaged) {
            os << "[omit]"; // You can replace this by anything else.
            return os;
        }
        return os << p.stored;
    }

    friend std::ostream& operator<<(std::ostream& os, Printer&& p) {
        if (!p.storaged) {
            os << "[omit]"; // You can replace this by anything else.
            return os;
        }
        return os << p.stored;
    }

    void print() {storaged = true; }
private:
    std::string stored;
    bool storaged;
};

Printer printThisLater(const std::string& str) {
    return Printer(str);
}

void printItNow(Printer &p) {
    p.print();
}

int main() {

    int x = 10, y = 59;
    auto tmp = printThisLater("Hello World");
    std::cout << tmp << x << y;
    printItNow(tmp);
    std::cout << tmp << std::endl;
}
