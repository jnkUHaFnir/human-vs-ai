#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main() {
    // Open the file stream
    std::ofstream outputFile("output.txt");
  
    if (!outputFile) {
        std::cerr << "Failed to open the output file." << std::endl;
        return 1;
    }

    // Create a buffer (character array) to hold the formatted string
    char buffer[100];
  
    // Use sprintf to format the string, providing the buffer and the desired format
    std::string formattedString;
    sprintf(buffer, "The formatted string: %d", 123);
  
    // Insert the buffer into the string
    formattedString = buffer;
  
    // Write the formatted string to the file stream
    outputFile << formattedString;
  
    // Close the file stream
    outputFile.close();
  
    return 0;
}
