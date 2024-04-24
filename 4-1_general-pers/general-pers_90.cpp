#include <iostream>
#include <sstream>

bool stringToInt(const char* str, int& result) {
    std::istringstream ss(str);
    ss >> result;

    // Check if a conversion error occurred
    if (ss.fail() || !ss.eof()) {
        return false; // Conversion failed
    }

    return true; // Conversion successful
}

int main() {
    const char* str = "12345";
    int number;

    if (stringToInt(str, number)) {
        std::cout << "Successfully parsed: " << number << std::endl;
    } else {
        std::cerr << "Failed to parse the string to an integer." << std::endl;
    }

    return 0;
}
