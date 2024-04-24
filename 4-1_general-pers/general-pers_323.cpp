#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    // Create a file stream
    std::ofstream file("output.txt");
    
    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    // Create an ostringstream to format the string
    std::ostringstream oss;

    // Format the string
    int intValue = 10;
    float floatValue = 3.14f;
    std::string stringValue = "example";

    oss << "Integer value: " << intValue << ", Float value: " << floatValue << ", String value: " << stringValue;

    // Write the formatted string to the file stream
    file << oss.str() << std::endl;

    // Close the file stream
    file.close();

    return 0;
}
