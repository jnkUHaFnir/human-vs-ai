#include <iostream>
#include <cstdlib>
#include <cctype>

bool isPositiveInteger(const std::string &str) {
    if (str.empty()) {
        return false;
    }

    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "ERROR: No input provided." << std::endl;
        return 1;
    }

    if (!isPositiveInteger(argv[1])) {
        std::cerr << "ERROR: Input is not a positive integer." << std::endl;
        return 1;
    }

    if(std::stoi(argv[1]) < 1){
        std::cerr << "ERROR: Input is not a positive integer." << std::endl;
        return 1;    
    }

    // Proceed with the rest of your program
    return 0;
}
