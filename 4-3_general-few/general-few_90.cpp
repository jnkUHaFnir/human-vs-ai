#include <iostream>
#include <sstream>

int parseToInt(const char* str) {
    std::istringstream iss(str);
    int result = 0;
    
    if (!(iss >> result)) {
        throw std::invalid_argument("Invalid input. Cannot convert to integer.");
    }
    
    char remaining_char;
    if (iss >> remaining_char) {
        throw std::invalid_argument("Invalid input. Not a valid integer number.");
    }
    
    return result;
}

int main() {
    const char* str = "1234";
    
    try {
        int parsedNum = parseToInt(str);
        std::cout << "Parsed integer: " << parsedNum << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
