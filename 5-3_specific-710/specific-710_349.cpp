#include <iostream>
#include <string>
#include <sstream>

int parseInt(const char* str) {
    std::stringstream ss(str);
    int parsedInt = 0;
    
    if (!(ss >> parsedInt)) {
        throw std::invalid_argument("Invalid input. Cannot parse the integer.");
    }
    
    char leftover;
    if (ss >> leftover) {
        throw std::invalid_argument("Invalid input. Not an integer.");
    }
    
    return parsedInt;
}

int main() {
    const char* str = "1234";
    
    try {
        int result = parseInt(str);
        std::cout << "Parsed integer: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
