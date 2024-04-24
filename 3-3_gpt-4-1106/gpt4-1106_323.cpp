#include <iostream>
#include <fstream>
#include <string>
#include <cstdio> // for sprintf

int main() {
    // The format string (like in printf)
    const char* format = "Hello, %s! You have %d new messages.\n";
    // Values to be formatted into the string
    const char* name = "John Doe";
    int numMessages = 42;

    // Buffer for sprintf - ensure it's large enough for the resulting string
    char buffer[1024];

    // Use snprintf to format the string safely
    std::snprintf(buffer, sizeof(buffer), format, name, numMessages);

    // Convert to std::string (optional, if you prefer to work with std::string)
    std::string formattedString = buffer;

    // Filename to write to
    std::string filename = "output.txt";

    // Create an ofstream for output
    std::ofstream outFile(filename);

    // Make sure the file stream is open
    if (!outFile.is_open()) {
        std::cerr << "Failed to open the file for writing.\n";
        return 1;
    }

    // Send the formatted std::string to the file stream
    outFile << formattedString;

    // Close the file stream
    outFile.close();

    return 0;
}
