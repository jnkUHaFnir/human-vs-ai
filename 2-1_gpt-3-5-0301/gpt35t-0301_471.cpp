#include <iostream>
#include <streambuf>
#include <string>

class delayed_string_buffer : public std::stringbuf {
public:
    int sync() override {
        // do nothing on sync, so that characters are stored in the buffer
        return 0;
    }

    std::string get_string() const {
        return str();
    }
};

class delayed_string_stream : public std::ostream {
public:
    delayed_string_stream() :
        std::ostream(new delayed_string_buffer) {}

    ~delayed_string_stream() {
        delete rdbuf();
    }

    // the << operator should do nothing so that characters are stored in the buffer
    delayed_string_stream& operator<<(const void*) { return *this; }
    delayed_string_stream& operator<<(std::ios& (*)(std::ios&)) { return *this; }
    delayed_string_stream& operator<<(std::ostream& (*)(std::ostream&)) { return *this; }
    template <typename T>
    delayed_string_stream& operator<<(const T&) { return *this; }

    std::string get_string() const {
        return static_cast<delayed_string_buffer*>(rdbuf())->get_string();
    }
};

delayed_string_stream printThisLater(const std::string& str) {
    delayed_string_stream ss;
    ss << str;
    return ss;
}

std::string printItNow() {
    return "";
}

int main() {
    int x = 10, y = 59;

    std::cout << printThisLater("Hello World") << x << y << printItNow(); // prints "Hello World1059"

    std::string str = printThisLater("Delayed string").get_string();
    std::cout << "The delayed string is: " << str << '\n'; // prints "The delayed string is: Delayed string"
} 