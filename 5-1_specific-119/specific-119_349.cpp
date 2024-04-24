#include <iostream>
#include <string>
#include <sstream>

int parseInt(const char* str) {
    int result = 0;
    std::istringstream iss(str);
    
    if (!(iss >> result)) {
        // Parsing failed, handle error
        throw std::invalid_argument("Invalid input. Failed to convert to integer.");
    }

    return result;
}

int main() {
    const char* str = "123";

    try {
        int num = parseInt(str);
        std::cout << "Parsed integer: " << num << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
