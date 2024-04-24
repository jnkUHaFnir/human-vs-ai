#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt", std::ios::binary);

    char numbers[4][16]; // Increase the buffer size by 1 to accommodate the null terminator

    for (unsigned lines = 0; lines < 4; ++lines) {
        if (!file.getline(numbers[lines], 16, '\n')) { // Read up to 15 characters, 16th for the null terminator
            if (file.eof()) {
                std::cout << "End of file reached.\n";
                break;
            } else {
                std::cerr << "Error reading line " << lines + 1 << std::endl;
                break;
            }
        }
    }

    for (unsigned i = 0; i < 4; ++i) {
        std::cout << "Number " << i + 1 << ": " << numbers[i] << std::endl;
    }

    return 0;
}
