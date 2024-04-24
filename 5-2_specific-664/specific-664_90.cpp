#include <iostream>
#include <sstream>

int parseToInt(const char* str) {
    int result;
    std::istringstream iss(str);
    
    // Try to extract an integer from the input string
    if (!(iss >> result)) {
        // Clear any error flags
        iss.clear();
        
        // Handle the error by throwing an exception or return an error code
        throw std::invalid_argument("Invalid input");
    }
    
    // Check if there is any remaining input after the integer
    char remaining;
    if (iss >> remaining) {
        // Handle the error by throwing an exception or return an error code
        throw std::invalid_argument("Invalid input");
    }
    
    return result;
}

int main() {
    const char* str = "123";
    
    try {
        int result = parseToInt(str);
        std::cout << "Parsed integer: " << result << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        // Handle the error as needed
    }
    
    return 0;
}
