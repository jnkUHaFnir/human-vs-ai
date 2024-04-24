#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    char buffer[100]; // Make sure it's large enough to hold the formatted string

    // Use snprintf to format the string
    snprintf(buffer, sizeof(buffer), "%s", str.c_str());

    // Open a file stream to write the data
    std::ofstream file("output.txt");
    if (file.is_open()) {
        file << buffer << std::endl;
        file.close();
        std::cout << "Data written to file successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }

    return 0;
}
