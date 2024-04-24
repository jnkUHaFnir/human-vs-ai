#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt", std::ios::in);

    char numbers[4][16]; // Change the size to accommodate null terminator

    unsigned lines = 0;
    while (file.getline(numbers[lines], 16)) {
        ++lines;
        if (lines >= 4) { // Max 4 lines
            break;
        }
    }

    // Print the numbers to verify
    for (unsigned i = 0; i < lines; ++i) {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}
