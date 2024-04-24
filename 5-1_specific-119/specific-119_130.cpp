#include <iostream>
#include <cstdlib>
#include <cctype>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "No input provided!" << std::endl;
        return 1;
    }

    for (size_t i = 0; argv[1][i] != '\0'; i++) {
        if (!std::isdigit(argv[1][i])) {
            std::cerr << "Error: Input is not a positive integer!" << std::endl;
            return 1;
        }
    }

    int inputNumber = std::atoi(argv[1]);
    if (inputNumber < 1) {
        std::cerr << "Error: Input is not a positive integer!" << std::endl;
        return 1;
    }

    std::cout << "Input is a positive integer: " << inputNumber << std::endl;
    
    return 0;
}
