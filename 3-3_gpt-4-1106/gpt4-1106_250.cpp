#include <fstream>
#include <cstring>
#include <cstdlib>

int main() {
    std::ifstream file("data.txt");
    std::string line;

    while (std::getline(file, line)) {
        char* lineCStr = const_cast<char*>(line.c_str());
        char* token = std::strtok(lineCStr, " ");
        while (token != nullptr) {
            float value = std::strtof(token, nullptr);
            // Do something with value...
            token = std::strtok(nullptr, " ");
        }
    }

    return 0;
}
#include <charconv>
#include <string>
#include <fstream>

int main() {
    std::ifstream file("data.txt");
    std::string line;

    while (std::getline(file, line)) {
        const char* begin = line.data();
        const char* end = line.data() + line.size();
        
        for (int i = 0; i < 3; ++i) {
            float value;
            auto [ptr, ec] = std::from_chars(begin, end, value);
            if (ec == std::errc()) {
                // Value successfully parsed, do something with it.
                begin = ptr + 1; // Skip the space too
            } else {
                // Handle error
                break;
            }
        }
    }

    return 0;
}
#include <boost/spirit/include/qi.hpp>
#include <string>
#include <fstream>
#include <vector>

namespace qi = boost::spirit::qi;

int main() {
    std::ifstream file("data.txt");
    std::string line;

    while (std::getline(file, line)) {
        std::vector<float> values;
        qi::parse(line.begin(), line.end(), qi::float_ >> *(' ' >> qi::float_), values);

        // Values vector now contains the parsed floats
        if (values.size() == 3) {
            // Use your floats
            float x = values[0], y = values[1], z = values[2];
            // Do something with x, y, z
        }
    }

    return 0;
}
