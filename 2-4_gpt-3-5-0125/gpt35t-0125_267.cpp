#include <fstream>
#include <string>

int main() {
    std::string str = "Hello, world!";
    
    // Convert std::string to char*
    const char* formattedString;
    formattedString = str.c_str(); // or use str.data() for more C++11 style

    // Use sprintf to format the string
    char buffer[100]; // Make sure the buffer is large enough
    int ret = sprintf(buffer, "Formatted String: %s", formattedString);

    // Send the formatted string into a file stream
    std::ofstream outFile("output.txt"); // Open file stream

    if (outFile.is_open()) {
        outFile << buffer; // Write formatted string to file
        outFile.close(); // Close file stream
    } else {
        std::cout << "Error opening file" << std::endl;
    }

    return 0;
}
