#include <iostream>
#include <sstream>
#include <string>

int parseStringToInt(const char* str) {
    std::istringstream iss(str);
    int result = 0;

    if (!(iss >> result)) {
        // Parsing failed, handle error here
        std::cerr << "Error: Unable to parse the input string into an integer.\n";
        // You can throw an exception here or return an error code
    }

    return result;
}

int main() {
    const char* inputStr = "123";
    int parsedInt = parseStringToInt(inputStr);
    
    if (parsedInt != 0) {
        std::cout << "Parsed integer: " << parsedInt << std::endl;
    }

    return 0;
}
