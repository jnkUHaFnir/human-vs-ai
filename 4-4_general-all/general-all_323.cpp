#include <cstdio>
#include <string>
#include <fstream>

int main() {
    std::string str = "Hello, World!";
    
    // Convert std::string to const char*
    const char* cstr = str.c_str();
    
    // Open a file stream
    std::ofstream file("output.txt");
    
    if (file.is_open()) {
        // Use fprintf to write the formatted string to the file stream
        fprintf(file, "%s\n", cstr);
        
        // Close the file stream when done
        file.close();
    } else {
        // Handle file open error
        std::cerr << "Error opening the file." << std::endl;
    }
    
    return 0;
}
