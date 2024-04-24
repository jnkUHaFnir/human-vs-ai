#include <iostream>
#include <string>
#include <sstream>

int stringToInt(const char *input) {
    std::istringstream ss(input);
    int result;
    if (!(ss >> result)) {
        throw std::invalid_argument("Invalid input. Cannot convert to int.");
    }
    char remaining;
    if (ss >> remaining) {
        throw std::invalid_argument("Invalid input. Extra characters after number.");
    }
    return result;
}

int main() {
    const char *input = "12345";
    try {
        int number = stringToInt(input);
        std::cout << "Parsed number: " << number << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
