#include <iostream>
#include <string>
#include <regex>

int main() {
    std::string inputData = "This is\n some 123 random *&^% data!";
    
    // Define the regex pattern to allow only letters, numbers, and spaces
    std::regex pattern("[^a-zA-Z0-9 ]");

    // Use regex_replace to remove unwanted characters
    std::string processedData = std::regex_replace(inputData, pattern, "");

    std::cout << "Processed data: " << processedData << std::endl;

    return 0;
}
