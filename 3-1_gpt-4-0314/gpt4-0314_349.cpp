#include <iostream>
#include <cstdlib>
#include <stdexcept>

int parseInt(const char *str) {
    char *end;
    long value = std::strtol(str, &end, 10); // Convert the string to a long integer

    if (end == str) {
        // No number was found
        throw std::invalid_argument("Invalid argument: Not a valid number");
    }

    if (*end != '\0') {
        // Some non-numeric characters were found after the number
        throw std::invalid_argument("Invalid argument: Additional non-numeric characters");
    }

    if (value < INT_MIN || value > INT_MAX) {
        // The value is out of the range of an int
        throw std::out_of_range("Out of range: Value too large or too small for int");
    }

    return static_cast<int>(value);
}

int main() {
    try {
        const char *str = "12345";
        int num = parseInt(str);
        std::cout << "Number: " << num << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
