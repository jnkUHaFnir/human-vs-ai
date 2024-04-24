#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>

int main() {
    std::string myString = "Hello, World!";
    char buffer[100]; // Make sure the buffer is large enough to hold the formatted string

    // Format the string using sprintf into the buffer
    sprintf(buffer, "%s", myString.c_str());

    // Open a file stream
    std::ofstream file("output.txt");

    // Check if the file is open
    if (file.is_open()) {
        // Write the formatted string to the file stream
        file << buffer << std::endl;

        // Close the file
        file.close();
        std::cout << "Data written to file successfully." << std::endl;
    } else {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    return 0;
}
