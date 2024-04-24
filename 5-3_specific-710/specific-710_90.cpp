#include <iostream>
#include <string>

int safeStringToInt(const char* str) {
    try {
        return std::stoi(str);
    } catch(const std::invalid_argument &ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
    } catch(const std::out_of_range &oor) {
        std::cerr << "Out of range error: " << oor.what() << std::endl;
    }
    return 0; // or handle the error in a different way based on your application's needs
}

int main() {
    const char* input = "12345"; // example input string
    int num = safeStringToInt(input);
    
    if (num != 0) {
        std::cout << "Successfully parsed integer: " << num << std::endl;
    } else {
        std::cerr << "Failed to parse integer" << std::endl;
    }

    return 0;
}
