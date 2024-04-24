#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    char numbers[4][16]; // Need space for null terminator

    // Read the numbers
    unsigned lines = 0;
    while (file.getline(numbers[lines], 16) && lines < 4) {
        // Print the numbers to verify they are read correctly
        std::cout << "Number " << lines + 1 << ": " << numbers[lines] << std::endl;
        ++lines;
    }

    file.close(); // Close the file when done

    return 0;
}
