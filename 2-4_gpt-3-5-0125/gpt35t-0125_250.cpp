#include <boost/spirit/include/qi.hpp>
#include <iostream>
#include <string>

namespace qi = boost::spirit::qi;

int main() {
    std::string line = "134.32 3545.87 3425";

    float x, y, z;
    auto it = line.begin();
    bool success = qi::phrase_parse(it, line.end(), qi::float_ >> qi::float_ >> qi::float_, qi::space, x, y, z);

    if (success && it == line.end()) {
        std::cout << "Parsed values: " << x << " " << y << " " << z << std::endl;
    } else {
        std::cerr << "Parsing failed" << std::endl;
    }

    return 0;
}
