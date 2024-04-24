#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt", std::ios::binary);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    char numbers[4][16]; // Increase the size by 1 to accommodate null terminator
    
    for (unsigned lines = 0; lines < 4; ++lines) {
        if (!file.getline(numbers[lines], 16)) { // Increase size by 1 to read '\n'
            break; // Break if unable to read a line
        }
    }

    // Output the numbers read
    for (unsigned i = 0; i < 4; ++i) {
        std::cout << "Number " << i+1 << ": " << numbers[i] << std::endl;
    }

    return 0;
}
