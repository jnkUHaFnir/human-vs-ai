#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string formattedString;
    char buffer[256]; // Adjust the buffer size as needed

    // Format the string using snprintf
    snprintf(buffer, sizeof(buffer), "Your formatted string here %d", 42);

    formattedString = buffer; // Copy the formatted string to std::string

    // Write the formatted string to a file stream
    std::ofstream file("output.txt");
    if (file.is_open()) {
        file << formattedString << std::endl;
        file.close();
    } else {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    return 0;
}
