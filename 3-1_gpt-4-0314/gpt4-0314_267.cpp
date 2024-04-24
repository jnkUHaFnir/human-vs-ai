#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main() {
    // Input string and file name
    std::string input = "This is an example.";
    std::string file_name = "output.txt";

    // Convert the input std::string to C-string
    const char* input_cstr = input.c_str();

    // Prepare the buffer
    char buffer[1024];

    // Format the input string using sprintf
    sprintf(buffer, "Formatted string: %s", input_cstr);

    // Open the file stream
    std::ofstream file_stream(file_name);

    // Check if the file stream is open
    if (file_stream.is_open()) {
        // Send the formatted string into the file stream
        file_stream << buffer;
        
        // Close the file stream
        file_stream.close();
        std::cout << "Data written to file: " << file_name << std::endl;
    }
    else {
        std::cerr << "Error opening file: " << file_name << std::endl;
    }

    return 0;
}
