#include <cstdio> // For sprintf
#include <fstream> // For file stream
#include <string>

int main() {
    std::string data = "Hello, world!";
    char buffer[100]; // Make sure the buffer is large enough to hold the formatted string

    // Format the string
    snprintf(buffer, sizeof(buffer), "Formatted string: %s", data.c_str());

    // Write the formatted string to a file
    std::ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << buffer << std::endl;
        outputFile.close();
        std::cout << "Formatted string successfully written to file." << std::endl;
    } else {
        std::cerr << "Error opening file for writing." << std::endl;
    }

    return 0;
}
