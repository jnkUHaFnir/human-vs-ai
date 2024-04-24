#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    char numbers[4][16]; // Each number needs space for 15 digits and 1 for null terminator

    for (unsigned lines = 0; lines < 4; ++lines) {
        if (!file.getline(numbers[lines], 16)) {
            break; // Exit the loop if unable to read a line
        }
    }

    // Output the numbers read
    for (unsigned i = 0; i < 4; ++i) {
        std::cout << "Number " << i+1 << ": " << numbers[i] << std::endl;
    }

    file.close();

    return 0;
}
