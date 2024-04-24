#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

int main() {
    std::string data = "Hello, World!";
    char buffer[256]; // Make sure the buffer is large enough to hold the formatted string

    // Format the string using sprintf
    sprintf(buffer, "%s formatted with sprintf\n", data.c_str());

    // Open a file stream
    std::ofstream file("output.txt");

    if (file.is_open()) {
        // Write the formatted string to the file stream
        file << buffer;

        // Close the file stream
        file.close();
        
        std::cout << "Data written to file." << std::endl;
    } else {
        std::cerr << "Error opening file." << std::endl;
    }

    return 0;
}
