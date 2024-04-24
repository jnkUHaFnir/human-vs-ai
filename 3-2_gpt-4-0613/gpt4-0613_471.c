#include <iostream>
#include <string> 

class DeferredOutput {
public:
    DeferredOutput(std::ostream& os) : m_os(os) {}

    DeferredOutput& operator<<(const std::string& str) {
        m_deferredMessage = str;
        return *this;
    }

    template<typename T>
    DeferredOutput& operator<<(const T& value) {
        m_os << value;
        return *this;
    }

    std::ostream& printItNow() {
        m_os << m_deferredMessage;
        return m_os;
    }

private:
    std::ostream& m_os;
    std::string m_deferredMessage;
};

int main() {
    int x = 10, y = 59;
    DeferredOutput out(std::cout);

    out << "Hello, World" << x << y;
    out.printItNow();
}
