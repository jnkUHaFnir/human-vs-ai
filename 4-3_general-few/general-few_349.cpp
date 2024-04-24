#include <iostream>
#include <string>
#include <sstream>

int parseToInt(const char *str) {
    std::string input(str);
    int result;
    std::istringstream ss(input);

    if (!(ss >> result)) {
        // Error handling: could not parse the input
        throw std::invalid_argument("Invalid input. Cannot convert to integer.");
    }

    // Check if there are any remaining characters in the input
    char leftover;
    if (ss >> leftover) {
        // Error handling: there are characters left in the input after parsing
        throw std::invalid_argument("Invalid input. Cannot convert to integer completely.");
    }

    return result;
}

int main() {
    const char *input = "123";
    try {
        int num = parseToInt(input);
        std::cout << "Parsed integer: " << num << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
