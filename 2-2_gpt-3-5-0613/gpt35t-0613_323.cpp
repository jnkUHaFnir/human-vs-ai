#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main() {
    std::string formattedString;
    char buffer[100]; // adjust the size as per your requirement

    // Format the string using sprintf
    sprintf(buffer, "The formatted string: %d %f", 10, 3.14);

    // Store the formatted string in a std::string
    formattedString = buffer;

    // Write the string to a file using file stream
    std::ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << formattedString;
        outputFile.close();
        std::cout << "Formatted string successfully written to file." << std::endl;
    } else {
        std::cout << "Failed to open file." << std::endl;
    }

    return 0;
}
