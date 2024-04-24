#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    char numbers[4][16]; // Need space for null terminator

    unsigned lines = 0;
    while (file.getline(numbers[lines], 16) && lines < 4) {
        ++lines;
    }

    file.close();

    // Output what was read to verify
    for (unsigned i = 0; i < lines; ++i) {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}
