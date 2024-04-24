#include <iostream>
#include <boost/spirit/include/qi.hpp>

int main() {
    namespace qi = boost::spirit::qi;

    std::ifstream file("your_file.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    float x, y, z;

    while (std::getline(file, line)) {
        auto it = line.begin();
        bool success = qi::phrase_parse(it, line.end(), qi::float_ >> qi::float_ >> qi::float_, qi::space, x, y, z);

        if (success && it == line.end()) {
            // Successfully parsed 3 floats from the line
            std::cout << "Parsed: x=" << x << ", y=" << y << ", z=" << z << std::endl;
        } else {
            std::cerr << "Parsing error on line: " << line << std::endl;
        }
    }

    file.close();

    return 0;
}
