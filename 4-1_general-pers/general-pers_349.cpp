#include <iostream>
#include <string>
#include <stdexcept>

int stringToInt(const char* str) {
    try {
        std::string s(str);
        size_t pos;
        int result = std::stoi(s, &pos); // Convert string to integer

        // Check for remaining characters in the string
        if (pos < s.length()) {
            throw std::invalid_argument("Could not convert the entire string to an integer.");
        }

        return result;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
        // You can throw or handle the exception according to your requirement
        throw;
    } catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
        // You can throw or handle the exception according to your requirement
        throw;
    }
}

int main() {
    const char* str = "12345";
    try {
        int value = stringToInt(str);
        std::cout << "Parsed integer: " << value << std::endl;
    } catch (...) {
        std::cerr << "Failed to parse the string into an integer." << std::endl;
        // Handle the error accordingly
    }
    return 0;
}
