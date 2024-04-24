#include <iostream>
#include <string>
#include <cctype> // For isalnum

std::string filterString(const std::string& input) {
    std::string output;
    for (char c : input) {
        // Check if the character is alphanumeric (letter or number) or a space.
        // If so, append it to the output string.
        if (std::isalnum(c) || c == ' ') {
            output.push_back(c);
        }
    }
    return output;
}

int main() {
    // Example usage
    std::string data = "This is an example.\nThis contains 123 numbers, and symbols!$%^&";
    std::string filteredData = filterString(data);
    std::cout << filteredData << std::endl;
    return 0;
}
