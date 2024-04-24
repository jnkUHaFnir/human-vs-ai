#include <iostream>
#include <cstdlib> // for std::strtol
#include <cerrno>  // for errno

bool parseToInt(const char* str, int& out) {
    char* end;
    errno = 0; // Reset errno to 0 before the call
    long int result = std::strtol(str, &end, 10);

    // Check for various possible errors
    if (end == str) {
        std::cerr << "Error: No digits were found.\n";
        return false;
    }
    if (errno == ERANGE || result > INT_MAX || result < INT_MIN) {
        std::cerr << "Error: Out of range.\n";
        return false;
    }
    if (*end != '\0') {
        std::cerr << "Error: Further characters after number: " << end << "\n";
        return false;
    }

    out = static_cast<int>(result);
    return true;
}

int main() {
    const char* str = "12345";
    int value;
    if (parseToInt(str, value)) {
        std::cout << "Parsed value: " << value << std::endl;
    } else {
        std::cout << "Failed to parse the integer." << std::endl;
    }
    // You can add more test cases to validate the robustness.
    return 0;
}
