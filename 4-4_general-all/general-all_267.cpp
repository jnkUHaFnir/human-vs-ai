#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

int main() {
    // Create a std::string to format
    std::string data = "Hello, World!";
    
    // Open a file stream
    std::ofstream file("output.txt");

    if (file.is_open()) {
        // Convert the std::string to a C string
        const char* cstr = data.c_str();
        
        // Use fprintf to format the string and send it to the file stream
        fprintf(file, "%s\n", cstr);
        
        // Close the file stream
        file.close();
        
        std::cout << "Data successfully written to file." << std::endl;
    } else {
        std::cerr << "Error opening file." << std::endl;
    }

    return 0;
}
