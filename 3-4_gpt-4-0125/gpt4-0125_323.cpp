#include <iostream>
#include <fstream> // For file operations
#include <string>
#include <cstdio> // For sprintf

int main() {
    // Assuming you're wanting to format these variables into a string
    int x = 10;
    double y = 20.5;
    const char* str = "example";

    // Step 1: Prepare a char buffer
    // Make sure the buffer is large enough for the resulting string
    char buffer[100]; // Adjust the size based on expected output

    // Step 2: Use sprintf to format
    sprintf(buffer, "Integer: %d, Double: %.2f, String: %s", x, y, str);

    // Optional: Convert to std::string if needed
    std::string formattedStr = buffer;

    // Step 3: Write to file stream
    std::ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << formattedStr << std::endl; // Using the std::string
        // Or, directly using buffer: outFile << buffer << std::endl;
        outFile.close();
    } else {
        std::cerr << "Failed to open file for writing.\n";
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() {
    int x = 10;
    double y = 20.5;
    const char* str = "example";

    std::stringstream ss;
    ss << "Integer: " << x << ", Double: " << y << ", String: " << str;

    std::ofstream outFile("output.txt");
    if(outFile.is_open()) {
        outFile << ss.str();
        outFile.close();
    } else {
        std::cerr << "Failed to open file for writing.\n";
    }

    return 0;
}
