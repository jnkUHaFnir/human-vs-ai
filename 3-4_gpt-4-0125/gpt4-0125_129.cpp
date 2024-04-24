#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt");  // Open in text mode by default

    // Allocate an extra char for each row for the null terminator
    char numbers[4][16];

    // Use standard C++ idiom for reading lines safely, ensuring we don't exceed array bounds
    for (unsigned lines = 0; lines < 4 && file.good(); ++lines) {
        // Read up to 14 characters to leave space for null terminator
        // Use std::noskipws to consider whitespace (spaces, tabs) as part of input
        file.getline(numbers[lines], 15);
        if (file.fail()) {
            // Clear failbit in case line was too long
            file.clear();
            // Ignore rest of line to prevent it from being read as the next number
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    // Example to show reading results
    for (int i = 0; i < 4; ++i) {
        std::cout << "Number " << i << ": " << numbers[i] << std::endl;
    }

    return 0;
}
