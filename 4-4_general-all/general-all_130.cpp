#include <iostream>
#include <cstdlib>
#include <cctype>

bool isPositiveInteger(const std::string& str) {
    if (str.empty() || (!std::isdigit(str[0]) && str[0] != '+')) {
        return false;
    }

    for (size_t i = 1; i < str.length(); ++i) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Error: Please provide an input." << std::endl;
        return 1;
    }

    if (!isPositiveInteger(argv[1])) {
        std::cerr << "Error: Input is not a positive integer." << std::endl;
        return 1;
    }

    int input = std::stoi(argv[1]); // Convert input to integer
    if (input < 1) {
        std::cerr << "Error: Input is not a positive integer." << std::endl;
        return 1;
    }

    // The input is a valid positive integer, continue with the program
    return 0;
}
