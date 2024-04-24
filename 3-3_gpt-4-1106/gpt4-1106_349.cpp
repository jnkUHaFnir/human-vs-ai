#include <iostream>
#include <cstdlib>
#include <cerrno>

int parseInt(const char *str) {
    char *endptr;
    errno = 0; // To distinguish success/failure after the call

    long value = std::strtol(str, &endptr, 10); // Base-10 conversion

    // Check for various possible errors
    if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
        || (errno != 0 && value == 0)) {
        // Handle overflow, underflow, or any system errors
        throw std::runtime_error("Conversion error: Value out of range or system error.");
    }

    if (endptr == str) {
        // No digits were found
        throw std::invalid_argument("Conversion error: No digits were found.");
    }

    // Check for any remaining characters after the number
    if (*endptr != '\0') {
        throw std::invalid_argument("Conversion error: Further characters after number.");
    }

    // If the value is beyond the range of an int, handle the error
    if (value < INT_MIN || value > INT_MAX) {
        throw std::out_of_range("Conversion error: Value out of range of int.");
    }

    return static_cast<int>(value);
}

int main() {
    const char *numberStr = "1234";

    try {
        int number = parseInt(numberStr);
        std::cout << "The parsed number is: " << number << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        // Handle the exception as needed
    }

    return 0;
}
