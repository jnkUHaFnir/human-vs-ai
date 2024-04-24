#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("numbers.txt");

    // check if file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Error opening file\n";
        return 1;
    }

    const int MAX_LINES = 4;
    const int MAX_DIGITS = 15;
    char numbers[MAX_LINES][MAX_DIGITS];

    // read up to MAX_LINES or until end of file
    int lines = 0;
    std::string line;
    while (std::getline(file, line) && lines < MAX_LINES) {
        // check if line is not too long
        if (line.length() >= MAX_DIGITS) {
            std::cerr << "Line too long\n";
            return 1;
        }
        // copy line to array
        std::strcpy(numbers[lines], line.c_str());
        ++lines;
    }

    // check if all lines were read
    if (lines < MAX_LINES) {
        std::cerr << "Not enough lines in file\n";
        return 1;
    }

    // print numbers
    for (int i = 0; i < MAX_LINES; ++i) {
        std::cout << numbers[i] << '\n';
    }

    return 0;
}
