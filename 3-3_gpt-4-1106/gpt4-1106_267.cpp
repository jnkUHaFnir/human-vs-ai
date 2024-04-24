#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdio> // for sprintf

int main() {
    // Suppose you want to format this string with some integer values
    std::string baseString = "The values are %d and %d.\n";
    int value1 = 42;
    int value2 = 105;

    // Create a sufficiently large buffer to hold the formatted string
    // You might want to ensure that the buffer is large enough
    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];

    // Use sprintf to format the string
    std::snprintf(buffer, BUFFER_SIZE, baseString.c_str(), value1, value2);

    // Construct a std::string from the buffer
    std::string formattedString(buffer);

    // Now write the formatted string to a file using an ofstream
    std::ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << formattedString;
        outFile.close();
        std::cout << "Formatted string written to file." << std::endl;
    } else {
        std::cerr << "Unable to open file." << std::endl;
        return 1;
    }

    return 0;
}
