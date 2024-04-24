#include <iostream>
#include <string>
#include <sstream>

int parseInteger(const char* input) {
    std::stringstream ss;
    int parsedInt = 0;
    
    // Load the input string into the stringstream
    ss << input;

    // Try to extract an integer from the stringstream
    if (!(ss >> parsedInt)) {
        // Failed to extract integer
        throw std::invalid_argument("Cannot parse input as integer.");
    }

    // Check if there are extra characters in the input
    char extra;
    if (ss >> extra) {
        throw std::invalid_argument("Extra characters after the integer.");
    }

    return parsedInt;
}

int main() {
    const char* input = "123";

    try {
        int result = parseInteger(input);
        std::cout << "Parsed integer: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
