#include <iostream>
#include <fstream>

int main() {
    std::ifstream file("numbers.txt", std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "File open error\n";
        return 1;
    }

    char numbers[4][15];
    unsigned lines = 0;

    while (file.getline(numbers[lines], 15, '\n')) {
        if (++lines >= 4) break; // Avoid reading more lines than what the array can hold
    }

    // Output the numbers read
    for (unsigned i = 0; i < lines; ++i) {
        std::cout << "Number " << i << ": " << numbers[i] << std::endl;
    }

    file.close(); // Close the file when done

    return 0;
}
