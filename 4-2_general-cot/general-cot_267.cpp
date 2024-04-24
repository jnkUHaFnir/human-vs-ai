#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ostringstream formattedStringStream;

    int intValue = 42;
    double doubleValue = 3.14159;
    std::string stringValue = "Hello, World!";

    // Format the string using ostringstream
    formattedStringStream << "Integer value: " << intValue << "\n";
    formattedStringStream << "Double value: " << doubleValue << "\n";
    formattedStringStream << "String value: " << stringValue << "\n";

    // Get the formatted string
    std::string formattedString = formattedStringStream.str();

    // Write the formatted string to a file stream
    std::ofstream file("output.txt");
    if (file.is_open()) {
        file << formattedString;
        file.close();
        std::cout << "Data written to file successfully.\n";
    } else {
        std::cerr << "Error opening file.\n";
    }

    return 0;
}
