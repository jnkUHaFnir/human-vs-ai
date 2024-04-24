#include <iostream>
#include <string>

int parseInteger(const char *str) {
    try {
        return std::stoi(str);
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        // Handle the error accordingly, possibly by returning an error code
        throw; // Re-throw the exception or handle as needed
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
        // Handle the error accordingly, possibly by returning an error code
        throw; // Re-throw the exception or handle as needed
    }
}

int main() {
    const char *str = "1234";
    
    try {
        int parsedInt = parseInteger(str);
        std::cout << "Parsed integer: " << parsedInt << std::endl;
    } catch (...) {
        // Handle any other exceptions if needed
        std::cerr << "Failed to parse integer." << std::endl;
    }

    return 0;
}
