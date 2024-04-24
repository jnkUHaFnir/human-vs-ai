#include <iostream>
#include <cstdio>
#include <fstream>

int main() {
    std::string myString = "Hello, world!";
    char buffer[100]; // Allocate a buffer to hold the formatted string

    // Use sprintf to format the string
    sprintf(buffer, "%s", myString.c_str());

    // Open a file stream
    std::ofstream outfile("output.txt");

    if (outfile.is_open()) {
        // Write the formatted string to the file stream
        fprintf(outfile, "%s", buffer);

        // Close the file stream
        outfile.close();

        std::cout << "String written to file successfully." << std::endl;
    } else {
        std::cerr << "Error opening the file." << std::endl;
    }

    return 0;
}
