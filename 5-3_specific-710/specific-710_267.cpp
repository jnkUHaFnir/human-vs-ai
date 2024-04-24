#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main() {
    std::string myString = "Hello, world!";
    
    // Determine the size needed for the formatted string
    int size = snprintf(nullptr, 0, "%s", myString.c_str());
    
    // Allocate memory for the formatted string
    char* formattedString = new char[size + 1];
    
    // Format the string
    snprintf(formattedString, size + 1, "%s", myString.c_str());
    
    // Open a file stream
    std::ofstream file("output.txt");
    
    // Write the formatted string into the file stream
    if (file.is_open()) {
        file << formattedString << std::endl;
        file.close();
    } else {
        std::cerr << "Error opening file." << std::endl;
    }
    
    // Cleanup
    delete[] formattedString;

    return 0;
}
