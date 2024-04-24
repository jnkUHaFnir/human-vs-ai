#include <iostream>
#include <sstream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide an input." << std::endl;
        return 1;
    }

    std::istringstream ss(argv[1]);
    int value;
    ss >> value;

    if (ss.fail() || value <= 0 || ss.tellg() != -1) {
        std::cerr << "Input is not a positive integer." << std::endl;
        return 1;
    }

    std::cout << "Input is a positive integer." << std::endl;

    return 0;
}
