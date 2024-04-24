#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile;
    std::string fileName, line;

    // Prompt the user to select the file using the Chromebook file picker
    std::cout << "Please select the file to read: ";
    std::cin >> fileName;

    // Open the selected file
    inputFile.open(fileName);
    if (!inputFile) {
        std::cout << "Error opening file. Please make sure the file exists." << std::endl;
        return 1;
    }

    // Read and process the file
    while (std::getline(inputFile, line)) {
        // Process each line of the file here
        // Example: split the line by spaces and print the data
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0;
}
