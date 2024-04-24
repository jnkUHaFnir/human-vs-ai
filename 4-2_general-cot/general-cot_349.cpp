#include <iostream>
#include <string>
#include <sstream>

int parseStringToInt(const char *str) {
    std::istringstream iss(str);
    int result = 0;
    
    // Try to parse the string
    if (!(iss >> result)) {
        // Clear any error flags set by the failed conversion
        iss.clear();
        
        // Handle the error (for example, you can throw an exception)
        throw std::invalid_argument("Invalid input. Could not convert to integer.");
    }
    
    return result;
}

int main() {
    const char *input = "42";

    try {
        int number = parseStringToInt(input);
        std::cout << "Parsed number: " << number << std::endl;
    } catch(const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
