#include <iostream>
#include <string>
#include <cstdio>

int main() {
    std::string myString = "Hello, World!";
    char buffer[100]; // Ensure buffer is large enough to hold the formatted string

    // Format the string into the buffer
    int result = snprintf(buffer, sizeof(buffer), "%s", myString.c_str());

    if (result >= 0 && result < sizeof(buffer)) {
        // Open file stream
        FILE* file = fopen("output.txt", "w");
        
        if (file != NULL) {
            // Write the buffer to the file stream
            fprintf(file, "%s\n", buffer);
            
            // Close the file stream
            fclose(file);
        } else {
            std::cerr << "Error opening file!" << std::endl;
        }
    } else {
        std::cerr << "Error formatting string!" << std::endl;
    }

    return 0;
}
