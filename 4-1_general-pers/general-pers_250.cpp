#include <boost/fusion/adapted/std_tuple.hpp>
#include <boost/spirit/home/x3.hpp>
#include <boost/spirit/include/qi.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>

namespace x3 = boost::spirit::x3;

// Define a struct to hold the parsed float values
struct FloatValues {
    float x, y, z;
};

// Define a grammar using Boost.Spirit
auto const float_parser = x3::float_;

auto const parser = float_parser >> float_parser >> float_parser;

// Function to parse a line into FloatValues using Boost.Spirit
bool parseLine(const std::string& line, FloatValues& values) {
    auto iter = line.begin();
    return x3::parse(iter, line.end(), parser, values);
}

int main() {
    std::ifstream file("your_file_path.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        FloatValues values;
        if (parseLine(line, values)) {
            // Process the parsed float values (values.x, values.y, values.z)
            std::cout << "Parsed values: " << values.x << " " << values.y << " " << values.z << std::endl;
        } else {
            std::cerr << "Error parsing line: " << line << std::endl;
        }
    }

    file.close();
    
    return 0;
}
