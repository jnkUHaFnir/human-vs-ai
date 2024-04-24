#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main() {
    // The variables you want to use in the formatted string
    int value1 = 42;
    double value2 = 3.14;

    // Buffer to store the formatted string (increase the size if necessary)
    char buf[256];

    // Format the string using sprintf
    sprintf(buf, "Value 1: %d, Value 2: %.2f", value1, value2);

    // Convert the char buffer into a std::string
    std::string formattedString(buf);

    // Open the file stream
    std::ofstream file("output.txt");

    // Send the formatted string to the file stream
    file << formattedString;

    // Close the file stream
    file.close();

    return 0;
}
