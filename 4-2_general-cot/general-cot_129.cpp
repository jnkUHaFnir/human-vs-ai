#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt", std::ios::binary);

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    char numbers[4][16]; // Need space for null terminator

    for (unsigned lines = 0; lines < 4; ++lines) {
        if (!file.getline(numbers[lines], 16, '\n')) {
            break; // Exit the loop if reading fails
        }
    }

    for (unsigned i = 0; i < 4; ++i) {
        std::cout << "Number " << i + 1 << ": " << numbers[i] << std::endl;
    }

    return 0;
}
